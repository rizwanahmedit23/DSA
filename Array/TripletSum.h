int tripletSum(int *arr, int n, int nums)
{
	//Write your code here
	int ans = 0;
    sort(arr, arr+n);
    for(int c=0;c<n-2;c++){
        int i = c+1,j=n-1;
        int num = nums - arr[c];
        while(i<j){
            if(arr[i]+arr[j]<num)
                i++;
            else if(arr[i]+arr[j]>num)
                j--;
            else{
                if(arr[i]==arr[j]){
                    int count = j-i+1;
                    ans = ans + (count*(count-1))/2;
                    break;
                }
                int c1=0,c2=0;
                for(int k=i;arr[k]==arr[i];k++){
                    c1++;
                }
                for(int k=j;arr[k]==arr[j];k--){
                    c2++;
                }
                ans = ans +  c1*c2;;
                i=i+c1; j=j-c2;
            }
        }
        // i=c;
        // while(arr[c]==arr[i]){
        //     i++;
        // }
        // c += (i-c);
    }
    return ans;
}
    
    
//     /*
//     int ans =0;
//     for(int i=0;i<n-2;i++){
//         for(int j=i+1;j<n-1;j++){
// 			for(int k=j+1;k<n;k++){
//                 if(arr[i]+arr[j]+arr[k] == num){
// 					ans ++;
//                 }
//             }
//         }
//     }
//     return ans;
//     */