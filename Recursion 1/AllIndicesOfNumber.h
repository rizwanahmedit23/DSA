
int allIndexes(int input[], int size, int x, int output[]) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Save all the indexes in the output array passed and return the size of output array.
     Taking input and printing output is handled automatically.
  */
	if(size == 1){
		if(input[0] == x){
            output[0]==0;
            return 1;
        }
        else
            return 0;
    }
    
    int smallOutput = allIndexes(input, size-1, x, output);
    int ans = smallOutput;
    if(input[size-1] == x){
		output[smallOutput]=size-1;
        ans = smallOutput+1;
    }
	return ans;
}
