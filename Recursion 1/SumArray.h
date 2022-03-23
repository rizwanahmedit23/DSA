int sum(int input[], int n) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Return output and don't print it.
     Taking input and printing output is handled automatically.
  */
	if(n == 1){
        return input[0];
    }
    int smallOutput = sum(input, n-1);
    return input[n-1] + smallOutput; 
}
