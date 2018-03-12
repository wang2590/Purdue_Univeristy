// Do not remove #ifdef ... #endif before and after each function.
// 
// They are used to test different functions in your program and give
// partial credits, in case your program does not work completely.

#include "student.h"
#include "msort.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NAME_LENGTH 80

//int compare1(const void * a,const void * b);
//int compare2(const void * a,const void * b);
//int compare3(const void * a,const void * b);

void StudentPrint(Student * stu, int num)
{
	printf("There are %d students\n", num);
	for (int ind = 0; ind < num; ind ++)
	{
		printf("ID = %d, First Name = %s, Last Name = %s\n",
				stu[ind].ID,  stu[ind].firstname, stu[ind].lastname);
	}
}

#ifdef TEST_READ
// return false if anything is wrong 
// return true if reading the file successfully and the data is save in
// the allocated memory
// input: filename, the name of the input file
// output: address of the allocated memory
// output: number of students
bool StudentRead(char * filename, Student * * stu, int * numelem)
{
	// open the file to read
	FILE* inFile = fopen(filename,"r");

	// if fopen fails, return false
	// do not use fclose since fopen already fails
	if(inFile == NULL)
	{
		return false;
	}

	// count the number of lines to determine the number of students
	int line = 0;
	char ch;
	while((ch = fgetc(inFile))!=EOF)
	{
		if(ch == '\n'){line++;}
	}	
//	*numelem = line;
	
	// return to the beginning of the file
	// you can use fseek or
	// fclose followed by fopen
	// You need to check whether fseek or fopen fails
	// Do not use rewind because it does not report whether it fails

/*	if(fseek(inFile,0,SEEK_END) != 0)
	{
		return false;
	}
*/
	fclose(inFile);
	FILE * file1 = fopen(filename,"r");
	
	if(file1 == NULL){return false;}	
	// allocate memory for the data
	//Student *student = malloc(sizeof(Student) * numelem);
	
	Student * z;
	z = malloc(sizeof(Student) * line);
	*numelem = line;
	// check whether memory allocation fails
	if(z == NULL){fclose(file1); return false;}

	// read the data from the file and store the data in the allocated memory
/*	int i = 0;
//	int check = 0;
	for(i = 0; i < (line); i++){
    if((fscanf(inFile, "%d %s %s\n", &(z[i].ID), (z[i].firstname), (z[i].lastname))) != 3)
		{
			return false;
		}
	}
*/
	int i = 0;
	int check = 0;
	for(i = 0; i < line; i++)
	{
	check = fscanf(file1,"%d %s %s",&(z[i].ID),(z[i].firstname),(z[i].lastname));
	
	if(check != 3){fclose(file1); return false;}
	}
//	printf("ID:%d \n",z[i].ID);}
	*stu = z;
	// close the file
//	printf("z-ID: %d \n",z[0].ID);
	fclose(file1);
	return true;

}
#endif

#ifdef TEST_WRITE
// return false if anything is wrong 
// return true if writing the file successfully
// input: filename, the name of the output file
// input: address of the student array
// input: number of students

bool StudentWrite(char * filename, Student * stu, int numelem)
{
	// open the file to write 
	FILE *outFile = fopen(filename, "w");

	// if fopen fails, return false
	// do not use fclose since fopen already fails
	if(outFile == NULL)
	{
	//	printf("failed to open outfile1\n");
		return false;
	}
	// write the students to the output file
		int i;
		for(i =0; i < numelem;i++)
		{
			if(fprintf(outFile,"%d %s %s\n",stu[i].ID, (stu[i]).firstname, (stu[i]).lastname) < 0){return false;}
		}
	fclose(outFile);
	return true;
}
#endif 

#ifdef TEST_SORTID
int compare1(const void *a, const void *b)
{
	const Student* value1 = (const Student*)a;
	const Student* value2 = (const Student*)b;
	if(value1->ID < value2->ID) { return -1; }
	if(value1->ID == value2->ID) {return 0; }
	return 1;
}
void StudentSortbyID(Student * stu, int numelem)
{
	msort((&stu[0]), numelem,compare1);
}
#endif

#ifdef TEST_SORTFIRSTNAME
int compare2(const void *a,const void *b)
{
	const Student* value1 = (const Student*)a;
	const Student* value2 = (const Student*)b;
	return(strcmp(value1 -> firstname, value2 -> firstname));

}
int compare3(const void *a,const void *b)
{
	const Student* value1 = (const Student*)a;
	const Student* value2 = (const Student*)b;
	return(strcmp(value1 -> lastname, value2 -> lastname));
}	
void StudentSortbyFirstName(Student * stu, int numelem)
{
	msort((&stu[0]),numelem,compare2);
}
#endif

#ifdef TEST_SORTLASTNAME

void StudentSortbyLastName(Student * stu, int numelem)
{
	msort((&stu[0]),numelem,compare3);
}
#endif
