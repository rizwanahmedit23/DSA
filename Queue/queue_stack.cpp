#include <iostream>
#include <stack>
using namespace std;

class queue{
    stack<int> s1;
    stack<int> s2;
    public:
        void enqueue(int item){
            s1.push(item);
        }
        int dequeue(){
            if (s1.empty() && s2.empty()){
                cout<< "Queue is empty:";
                return -1;
            }            
            if (s2.empty()){
                while(!s1.empty()){
                    s2.push(s1.top());
                    s1.pop();
                }
            }
            int topval=s2.top();
            s2.pop();
            return topval;
        }
        bool isempty(){
            if(s1.empty() && s2.empty()){
                return 1;
            }
            return 0;
        }
};
int main(){
    queue q;
    q.enqueue(2);
    q.enqueue(5);
    q.enqueue(6);
    q.enqueue(7);
    q.enqueue(15);

    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;

    q.enqueue(20);
    q.enqueue(25);
    q.enqueue(30);

    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;

    cout<<q.isempty()<<endl;
return 0;}