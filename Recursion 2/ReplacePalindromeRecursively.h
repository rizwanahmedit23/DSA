int length (char input []){
    int len = 0;
    for (int i=0;input[i]!='\0';i++){
        len++;
    }
    return len;
}
void replaceCharacter(char input[], char c1, char c2) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * No need to print or return the output. 
     * Change in the given input string itself.
     * Taking input and printing output is handled automatically.
     */
	int len = length(input);
    if(len == 0){
    return;
    }
    
    replaceCharacter(input+1,c1,c2);
    if(input[0] == c1){
        input[0] = c2;
    }
    return;
}