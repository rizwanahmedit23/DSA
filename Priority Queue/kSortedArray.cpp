#include<iostream>
#include<queue>
using namespace std;

void kSortedArray(int arr[], int n, int k){
    priority_queue<int> pq;
    for(int i=0;i<k;i++){
        pq.push(arr[i]);
    }
    int j = k;
    for(int i=0;i<n;i++){
        arr[i]=pq.top();
        pq.pop();
        if(j < n){
            pq.push(arr[j]);
            j++;
        }
    }
    return;
}
int main(){
    int arr[5] = {12,15,7,4,9};
    kSortedArray(arr, 5, 3);
    for(int i=0;i<5;i++){
        cout << arr[i] <<" ";
    }
}