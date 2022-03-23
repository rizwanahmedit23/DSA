#include <iostream>
using namespace std;

class Base{
    public:
        virtual void print(){
            cout<< "This is base class function";
        }
};
class Derived: public Base{
    public:
        void print (){
            cout<< "This is derived class function";
        }
};

int main(){
    Base b;
    Derived d;
    Base* baseptr;
    baseptr=&d;
    baseptr->print();
}
