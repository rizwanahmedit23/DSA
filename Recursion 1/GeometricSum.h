double geometricSum(int k) {
    // Write your code here
	if(k == 0){
		return 1;
    }
    double smallOutput = geometricSum(k-1);
	double ans = smallOutput + 1/pow(2,k);
    return ans;
}


