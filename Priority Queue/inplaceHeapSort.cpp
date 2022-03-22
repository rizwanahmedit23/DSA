#include<iostream>
using namespace std;

void inplaceHeapSort(int input[], int n){
    // Build the heap in input array
    for(int i=1;i<n;i++){

        //assume i=1 element inserted
        //Up Heapify

        int childIndex = i;
        while(childIndex != 0){
            int parentIndex = (childIndex - 1)/2;
            if(input[parentIndex]<input[childIndex]){
                break;
            }
            int temp = input[parentIndex];
            input[parentIndex] = input[childIndex];
            input[childIndex] = temp;

            childIndex = parentIndex;
        }
    }

    //Remove Elements
    for(int i =n-1;i>0;i--){
        //Swap first and ith element
        int temp = input[i];
        input[i]=input[0];
        input[0]=temp;

        //assume ith element is removed
        //down heapify till i-1th element
        int size = (i-1) + 1;//i-1 element present in heap
        int lastIndex = i - 1;
        int parentIndex = 0;
        while(parentIndex < lastIndex){
            int leftChildIndex = 2*parentIndex + 1;
            int rightChildIndex = 2*parentIndex + 2;
            int minChildIndex;//It is needed to compare with parent for possible swap 
            if(leftChildIndex > lastIndex){//leftChildIndex does not exist
                //Because it is  a CBT , right child index also does not exist
                break;//No more elements left to heapify
            }
            minChildIndex = leftChildIndex;
            if(rightChildIndex <= lastIndex){//right child exists , so automatically left child also exists
                if(input[rightChildIndex] < input[leftChildIndex]){//update minChildIndex
                    minChildIndex = rightChildIndex;
                }
            }
            //if I am here it is obvious that atleast One Child Exists
            //Also it is certain that minChildIndex has been Initialized

            //Compare input's minChildIndex, paarentIndex
            if(input[parentIndex] < input[minChildIndex]){
                //Stop since Heapify completed
                //No firther element need to be compared
                break;
            }
            //swap needed
            int temp = input[parentIndex];
            input[parentIndex]=input[minChildIndex];
            input[minChildIndex]=temp;

            //update parent for next iteration
            parentIndex = minChildIndex;
        }
        //we have sorted the array in decreasing order.

    }
}

int main(){
    int arr[5]={5,8,3,4,16};
    inplaceHeapSort(arr, 5);
    for(int i=0;i<5;i++){
        cout<< arr[i]<<" ";
    }
    return 0;
}