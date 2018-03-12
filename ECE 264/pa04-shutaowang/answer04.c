#include <stdio.h>
#include <stdbool.h>
#include "pa04.h"

// must enclose the function by #ifdef TEST_INTEGRATE 
// and #endif to enable partial credits
#ifdef TEST_INTEGRATE
void integrate(Integration * intrg)
{
  double deltaX = (intrg-> upperlimit - intrg -> lowerlimit) / intrg -> intervals;
  double height =0;
  double sumIntegral = 0;
  for (int i = 0;i < intrg -> intervals; i++)
  {
	double width =(deltaX * i + intrg -> lowerlimit);
	height =(intrg -> func(width));
	sumIntegral += height * deltaX;	
  }
	intrg -> answer = sumIntegral;
}
 #endif // TEST_INTEGRATE

// must enclose the function by #ifdef RUN_INTEGRATE
// and #endif to enable partial credits

#ifdef RUN_INTEGRATE
bool  runIntegrate(char * infilename, char * outfilename)
{
	// return true if it can successfully open and read the input 
	// and open and write the output
	// return false when encountering any problem

	// open the input file name for reading
	FILE* fp;
	fp = fopen(infilename,"r");



	// if fopen fails, return false
	if(fp == 0)
	{
		return false;	
	}


	// read one double from the input file and store it in 
	// intrg's lowerlimit
	// use fscanf
	// check the return value. If the return value is not one
	// close the file and return false
	Integration intrg;
	double input = fscanf(fp, "%lf", &(intrg.lowerlimit));
			if(input != 1)
			{
			fclose(fp);
			return false;
			}


			// read one double from the input file and store it in 
			// intrg's upperlimit
			// use fscanf
			// check the return value. If the return value is not one
			// close the file and return false

			double input1 = fscanf(fp, "%lf", &(intrg.upperlimit));
			if(input1 != 1)
			{
			fclose(fp);
			return false;
			}



			// read one int from the input file and store it in 
			// intrg's intervals
			// use fscanf
			// check the return value. If the return value is not one
			// close the file and return false

	int input3 = fscanf(fp,"%d", &(intrg.intervals));
	if(input3 != 1)
	{
		fclose(fp);
		return false;
	}


	// close the input file

	fclose(fp);

	// open the output file for writing
	// if fopen fails, return false
	FILE* fp1 = fopen(outfilename,"w");
	if(fp1 == NULL)
	{
		return false;
	}

	// create an array of funcptr called funcs with five elements:
	// func1, func2, ..., func5
	funcptr funcs[] = {func1, func2, func3, func4, func5};

	// go through the elements in funcs 
	// for each element, call integrate for that function
	// write the result (stored in intrg's answer to 
	// the output file. each answer occupies one line (add "\n")
	// use fprintf
	int func_num = sizeof(funcs) / sizeof(funcptr);
	for(int ct = 0; ct < func_num; ct++)
	{
		intrg.func = funcs[ct];
		integrate(&intrg);
		if(fprintf(fp1, "%f\n",intrg.answer) < 1)
		{
			fclose(fp1);
			return false;
		}
	}


	// check the return value of fprintf. 
	// If it is less one one, close the output
	// file and return false

	// after going through all functions in funcs
	// close the output file

	fclose(fp1);

	// if the function reaches here, return true

	return true;
}
#endif // RUN_INTEGRATE
