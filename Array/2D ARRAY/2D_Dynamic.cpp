#include<iostream>
using namespace std;

int main(){
    int r,c;
    cout<< "Enter size of row and column"<<endl;
    cin>>r>>c;

    int **a= new int*[r];

    cout<< "Enter array elements:"<<endl;

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            *(a+i)=new int [c]; //a[i]
        }
    }

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>> *(*(a+i)+j); //a[i][j]
        }
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout<<*(*(a+i)+j) <<" "; //a[i][j]
        }
    }
    return 0;
}