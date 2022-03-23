int length (char input []){
    int len = 0;
    for (int i=0;input[i]!='\0';i++){
        len++;
    }
    return len;
}
void removeConsecutiveDuplicates(char *input) {
	/* Don't write main().
	* Don't read input, it is passed as function argument.    
	* Change in the given string itself.
	* No need to return or print anything
	* Taking input and printing output is handled automatically.
	*/
	int len = length (input); 	
	if (len == 1){
        return;
    }
    
    removeConsecutiveDuplicates(input+1);
    if(input[0] == input[1]){
        for(int i=1;i<=len;i++){
            input [i-1] = input [i];
        }
    }
    return;
}