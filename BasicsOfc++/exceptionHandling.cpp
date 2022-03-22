#include <iostream>
using namespace std;

int main(){
    int num,den;
    int result;
    cin>> num>>den;
    try{
        if (den==0){
            throw den;
        }
    result = num/den;
    }
    catch(int ex){
        cout<< "Error: cannot divide by "<<ex<<endl;
        return 0; 
    }
    cout <<"The result is: " <<result;
}