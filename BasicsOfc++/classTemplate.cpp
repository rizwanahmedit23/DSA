#include<iostream>
using namespace std;

template <typename T>
class Area{
    T l,b;
    public: 
        Area(T l,T b){
            this->l=l;
            this->b=b;
            cout<< "Area is:"<< l*b<<endl;
        }
};
int main(){
    Area <int>box1(2,5);
    Area <float>box2(2.5,5.7);
}
