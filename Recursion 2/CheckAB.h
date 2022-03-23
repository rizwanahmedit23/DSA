bool checkAB(char input[]) {
	if(input[0]=='\0')
    {
        return true;
    }
    else if(input[0]=='a')
    {
        if(input[1]!='\0' && input[1]=='b' && input[2]!='\0' && input[2]=='b')
        {
            return checkAB(input+3);
        }
        return checkAB(input+1);
    }
    else{
    return false;
    }

}

