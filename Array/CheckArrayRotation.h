int arrayRotateCheck(int *input, int size)
{
    //Write your code here
		// if(size == 0 || size==1){
		// return 0;
		// }
    int i;
    bool flag = false;
    for(i=0; i<size-1;i++){
        if(input[i]>input[i+1]){
        	flag = true;
            break;   
        }
    }
    if(flag)
    	return i+1;
    return 0;
}