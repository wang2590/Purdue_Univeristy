#ifdef SELECTION_SORT
#include "pa01.h"
void selectSort(int * arr, int size)
//arr : the array to be sorted
//size : the number of elements in the array

// In each iteration, the number of elements to be sorted shrinks by one
// i.e., one element is at the correct position.
//
// Among the remaining elements, find the smallest value and put it 
// before the other unsorted elements
{
  int i;
  int j;
  int min;
  
  for (i = 0;i < size - 1; i++)
  {
     min = i;
     for(j = i + 1; j < size; j++)
     {
        if (arr[j] < arr[min])
	  min = j;
      }
      if (i != min)
        swap(&arr[i], &arr[min]);
  }
  return;
}

#endif	
