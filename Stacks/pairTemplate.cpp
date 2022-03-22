#include<iostream>
using namespace std;
template <typename T,typename V>

class Pair{
    T x;
    V y;

    public:

    void setX(T x){
        this->x = x;
    }
    void setY(V y){
        this->y = y;
    }
    T getX(){
        return x;
    }
    V getY(){
        return y;
    }
};

int main(){
    Pair<int,int> p1;
    p1.setX(10);
    p1.setY(20);
    Pair<Pair<int,int>, int> p;
    p.setX(p1);
    p.setY(30);
    cout<<p.getX().getX()<<" "<<p.getX().getY()<<" "<<p.getY();

}