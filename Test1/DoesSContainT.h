bool checksequenece(char large[] , char*small) {
	if(large[0]=='\0' && small[0]!='\0')
        return false;
    else if(large[0]!='\0' && small[0]=='\0')
        return true;
    else if(large[0]=='\0' && small[0]=='\0')
        return true;
    int i=0;
    for(;large[i]!='\0';i++){
        if(large[i] == small[0])
        break;
    }
    if(large[i]=='\0')
    	return false;
    return checksequenece(large+i+1, small+1);

    
}
