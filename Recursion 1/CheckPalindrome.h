int length(char input[]){
    int len = 0;
    for(int i = 0; input[i]!='\0';i++){
        len ++;
    }
    return len;
}
bool help(char input[], int si, int ei){
    // int len = length(input);
    // if(len <= 1){
    //     return true;
    // }
    if(si >= ei){
		return true;
    }
    bool smallOutput = help(input, si+1, ei-1);
    if(input[si]==input[ei])
        return smallOutput;
    else
        return false;
    
}
bool checkPalindrome(char input[]) {
    // Write your code here
	int len = length(input);
    bool ans = help(input, 0, len-1);
	return ans;
}


