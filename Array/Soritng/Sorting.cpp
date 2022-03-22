#include<iostream>
using namespace std;
int n;
void input(int arr[]){
    cout<< "Enter array elements:"<<endl;
    for (int i=0;i<n;i++){
        cin>>arr[i];
    }
}
void SelectionSort(int arr[]){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]>arr[j]){
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
}
void BubbleSort(int arr[]){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}
void InsertionSort(int arr[]){
    for(int i=1;i<=n;i++){
        int temp=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>temp){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
    }
}
void display(int arr[]){
    for(int i=0;i<n;i++){
        cout<< arr[i]<<" ";
    }
}
void Merge(int arr[],int l, int mid, int r){
    int n1=mid-l+1;
    int n2=r-mid;

    int a[n1];
    int b[n2];
    //inserting in temp arrays
    for(int i=0;i<n1;i++){
        a[i]=arr[l+i];
    }
    for(int i=0;i<n2;i++){
        b[i]=arr[mid+1+i];
    }
    //merge algo
    int i=0,j=0,k=l;
    while(i<n1 && j<n2){
        if(a[i]<b[j]){
            arr[k]=a[i];
            k++; i++;
        }
        else{
            arr[k]=b[j];
            k++; j++;
        }
    }

    while(i<n1){
        arr[k]=a[i];
        k++; i++;
    }

    while(j<n2){
        arr[k]=b[j];
        k++; j++;
    }
    
}
void MergeSort(int arr[],int l,int r){
    if(l<r){
        int mid=(l+r)/2;

        MergeSort(arr,l,mid);
        MergeSort(arr,mid+1,r);

        Merge(arr,l,mid,r);
    }
}
void swap(int arr[],int i, int j){
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}
int partition(int arr[],int l,int r){
    int pivot=arr[r];
    int i=l-1;
    for(int j=l;j<r;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr,i,j);
        }
    }
    swap(arr,i+1,r);
    return i+1;
}
void QuickSort(int arr[],int l,int r){
    if(l<r){
        int pi=partition(arr,l,r);
        QuickSort(arr,l,pi-1);
        QuickSort(arr,pi+1,r);
    }
}
int main(){
    cout<< "Enter number of elements:"<<endl;
    cin>> n;
    int arr[n];
    input(arr);
    InsertionSort(arr);
    display(arr);
}