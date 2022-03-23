bool isMaxHeap(int arr[], int n) {
    // Write your code here
    int check;
    for(int i=0;i<n;i++){
        int leftChildIndex = 2*i+1;
        int rightChildIndex = 2*i+2;        
        bool check = false;
        if(leftChildIndex < n){
            check = arr[i]>arr[leftChildIndex];
        }
        else{
			break;
        }
        if(rightChildIndex < n){
            check &= arr[i]>arr[rightChildIndex];
        }
        if(!check){
            return false;
        }
    }
    return true;
}