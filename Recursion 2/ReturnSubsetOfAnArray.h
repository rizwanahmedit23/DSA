/***
You need to save all the subsets in the given 2D output array. And return the number of subsets(i.e. number of rows filled in output) from the given function.

In ith row of output array, 1st column contains length of the ith subset. And from 1st column actual subset follows.
For eg. Input : {1, 2}, then output should contain 
	{{0}, 		// Length of this subset is 0
	{1, 2},		// Length of this subset is 1
	{1, 1},		// Length of this subset is also 1
	{2, 1, 2}}	// Length of this subset is 2

Don’t print the subsets, just save them in output.
***/

int subset(int input[], int n, int output[][20]) {
    // Write your code here
	if(n == 0){
		output[0][0] = 0;
        return 1;
    }
    
    int smallOutput = subset(input+1, n-1, output);
    for(int i =0; i<smallOutput;i++){
        int size = sizeof(output[i])/sizeof (output[i][0]);
        for(int j = size;j>=0;j--){
            if(j==0)
                output[i+smallOutput][j]=output[i][j]+1;
            else
                output[i+smallOutput][j+1]=output[i][j];
        }
        output[i+smallOutput][1]=input[0];
    }
    return smallOutput*2;
}
