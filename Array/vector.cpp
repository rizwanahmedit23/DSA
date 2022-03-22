#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n,m;
    cin>>n;
    vector<int> arr(n,0);
    cin>>m;
    int l,r;
    for(int i=0;i<m;i++){
        cin>>l>>r;
        arr[l]++;
        if(r<n)
            arr[r+1]--;
    }
    for(int i=1;i<n;i++){
        arr[i]+=arr[i-1];
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}