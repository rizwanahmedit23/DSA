#include <iostream>
using namespace std;
#include "Fraction.cpp"
int main(){
    Fraction f1(10,2);
    f1.print();
    Fraction f2 = ++(++f1);
    f1.print();
    f2.print();
}