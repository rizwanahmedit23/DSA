int multiplyNumbers(int m, int n) {
    // Write your code here
	if(n == 0 || m==0){
        return 0;
    }
    else if(n == 1){
		return m;
    }
    else if(m == 1){
        return n;
    }
    
    int smallOutput = multiplyNumbers(m, n-1);
	return smallOutput + m;
}


