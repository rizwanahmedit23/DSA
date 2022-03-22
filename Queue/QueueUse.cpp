#include<iostream>
using namespace std;
#include "QueueUsingArray.h"

int main(){
    QueueUsingArray<int> q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);

    cout<<q.front()<<endl;
    q.dequeue();
    cout<<q.front()<<endl;
}