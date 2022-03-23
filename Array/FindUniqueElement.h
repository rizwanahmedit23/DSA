int findUnique(int *arr, int n) {
    // Write your code here
    int ans=0;
    for(int i=0;i<n;i++){
        ans^=arr[i];
    }
    return ans;
    
    // int temp[n],i;
    // for(i=0;i<n;i++){
    //     temp[i]=0;
    // }
    // for(i=0;i<n;i++){
    //     temp[arr[i]]++;
    // }
    // for(i=0;i<n;i++){
    //     if(temp[i]==1)
    //         break;
    // }
    // return i;
}