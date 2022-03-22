#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n];

    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    int pd=a[1]-a[0];
    int curr=2;
    int ans=2;

    int j=2;
    while(j<n){
        if(pd==a[j]-a[j-1]){
            curr++;
            ans=max(ans,curr);
        }
        else{
            pd=a[j]-a[j-1];
            curr=2;
        }
        j++;
    }
    cout<<ans<<endl;
    return 0;
}