void swap(int *arr, int i, int j){
	int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
void reverse(int *arr, int si,int ei){
    int n=si+ei+1;
    for(int i=si;i<n/2;i++){
        swap(arr,i,n-1-i);
    }
}
void rotate(int *arr, int d, int n)
{
    //Write your code here
    /*
    if(n==0){
        return;
    }
    int temp ;
    d=d%n;
    while(d--){
		temp = arr[0];
        for(int i=1;i<n;i++){
            arr[i-1]=arr[i];
        }
        arr[n-1] = temp;
    }
    */
    
//     2nd approach
/*
    int temp[d];
    for(int i=0;i<d;i++){
        temp[i]=arr[i];
    }
    for(int i=d;i<n;i++){
        arr[i-d]=arr[i];
    }
    int j=0;
    for(int i=n-d;i<n;i++){
        arr[i]=temp[j];j++;
    }
*/
    
//    3rd approach
	reverse(arr, 0, n-1);
    reverse(arr, 0, n-d-1);
    reverse(arr, n-d,n-1);
}