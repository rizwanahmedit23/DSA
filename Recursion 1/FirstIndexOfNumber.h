int firstIndex(int input[], int size, int x) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Return output and don't print it.
     Taking input and printing output is handled automatically.
  */
	if(size == 1){
        if(input[0] == x)
            return 0;
        else
            return -1;
    }
    int smallOutput = firstIndex(input, size -1, x);
    if(smallOutput != -1)
        return smallOutput;
    if(input[size-1] == x)
        return size-1;
    else
        return -1;
}
