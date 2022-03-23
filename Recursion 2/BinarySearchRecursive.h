// // input - input array
// // size - length of input array
// // element - value to be searched
// int binarySearch(int input[], int size, int element) {
//     // Write your code here
// 	if(size == 0){
//         return -1;
//     }
    
//     int mid = size / 2;
//     if(element < mid){
//         return binarySearch(input, mid, element);
//     }
//     else if (element > mid){
//         return binarySearch(input+mid+1, size-mid-1, element);
//     }
//     else
//         return mid;
    
// }


int binary(int input[], int start, int end, int element){
    if(start > end){
        return -1;
    }
    int mid = (start+end)/2;
    if(input[mid] == element){
        return mid;
    } else if(input[mid] < element){
        return binary(input, mid+1, end,  element);
    } else{
        return binary(input, start, mid-1,  element);
    }
}
int binarySearch(int input[], int size, int element) {
    return binary(input, 0, size-1, element);
}


