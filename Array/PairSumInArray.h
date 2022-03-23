int pairSum(int *arr, int n, int num)
{
	//Write your code here
    int ans = 0;
    sort(arr, arr+n);
    int i = 0,j=n-1;
    while(i<j){
        if(arr[i]+arr[j]<num)
			i++;
        else if(arr[i]+arr[j]>num)
            j--;
        else{
			if(arr[i]==arr[j]){
				int count = j-i+1;
                ans = ans + (count*(count-1))/2;
                return ans;
            }
            int c1=0,c2=0;
            for(int k=i;arr[k]==arr[i];k++){
				c1++;
            }
            for(int k=j;arr[k]==arr[j];k--){
				c2++;
            }
            ans = ans + c1*c2;
            i=i+c1; j=j-c2;
        }
    }
    return ans;
}