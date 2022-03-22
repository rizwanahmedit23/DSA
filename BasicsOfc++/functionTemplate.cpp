#include<iostream>
using namespace std;

template <typename T, typename U>
U add (T x, U y){
    return (x+y); 
}

int main(){
    cout << "Addition of 2 and 4.5 is ";
    cout << add<int,float>(2,4.5)<<endl;
   
}