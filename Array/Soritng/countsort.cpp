#include<iostream>
#include<algorithm>

using namespace std;
main(){
    int A[]={5,8,2,8,6,3,9};
    int n=sizeof(A)/sizeof(int);
    
    int m=*max_element(A,A+n);
    
    int C[m+1];
    for (int i=0;i<m+1;i++){
        C[i]=0;
    }
    for (int i=0;i<n;i++){
        C[A[i]]++;
    }
    //       0 1 2 3 4 5 6 7 8 9
    //  C[]={0,0,1,1,0,1,1,0,2,1}
    int i=0,j=0;
    
    while (i<m+1){
        while(C[i]!=0){
            A[j]=i;
            C[i]--;
            j++;
        }
        i++;
    }
    for(i=0;i<n;i++){
        cout<< A[i] << " ";
    }
}