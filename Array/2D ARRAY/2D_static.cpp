#include<iostream >
using namespace std;

int main(){
    int arr[3][4];
    cout<<"Enter elements of a 2D array eith 3 rows and 4 columns: "<<endl;    
    for (int i=0;i <3;i++){
        for(int j=0;j<4;j++){
            cin>> arr[i][j];
        }
    }
    for (int i=0;i <3;i++){
        for(int j=0;j<4;j++){
            cout<< arr[i][j]<<" ";
        }
    }
    
}