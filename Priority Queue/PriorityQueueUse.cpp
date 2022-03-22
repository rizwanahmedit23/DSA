#include<iostream>
#include "PriorityQueue.h"
using namespace std;

int main(){
        PriorityQueue p;
        p.insert(5);
        p.insert(5);
        p.insert(5);
        p.insert(5);
        p.insert(5);
        for(int i=0;i<5;i++){
            cout<< p.removeMin()<<" ";
        }
    return 0;
}