int sumOfDigits(int n) {
    // Write your code here
	if(n/10 == 0){
        return n;
    }
    int smallOutput = sumOfDigits(n/10);
    return smallOutput + n%10;
}


