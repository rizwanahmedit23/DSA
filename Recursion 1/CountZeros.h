
int countZeros(int n) {
    // Write your code here
	if(n == 0){
        return 1;
    }
    if(n/10 == 0){
		return 0;
    }
    int smallOutput = countZeros(n/10);
	int ans = smallOutput;
    if(n%10 == 0)
        ans+=1;
    return ans;
}


