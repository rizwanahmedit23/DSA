/*
	To apply the method explained in the hint video, we have to add two more parameters in the function call. This can be done by calling a helper function from given function. The helper function can have three parameters: array, start index, end index.  
	
	Skeleton code to achieve this:
	#include <iostream>
	using namespace std;
	
	void quickSort(int input[], int start, int end)
	{
    		// your code goes here 
	}
	void quickSort(int input[], int size)
	{
    		quickSort(input, 0, size - 1);
	}
		
*/
void swap(int *input, int i, int j){
	int temp=input [i];
    input[i]=input[j];
    input[j]=temp;
}
int partition (int a[], int si, int ei){
    int pivot = si;
    int index = si+1;
    int i = si + 1;
    for(; i <= ei ; i++ )  
    {
        if( a[ i ] < a[pivot]){
            swap(a, i, index);
            index += 1;
        }
    }
    swap(a, si, index-1);
    return index-1;
}
void quickSort(int input[], int si, int ei){
    if(si>=ei){
        return ;
    }
    int pi = partition (input , si, ei);
    quickSort(input, si, pi-1);
    quickSort(input, pi+1, ei);
    return;
}
void quickSort(int input[], int size) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Change in the given array itself.
     Taking input and printing output is handled automatically.
  */
	quickSort(input, 0, size-1);
    return;
}