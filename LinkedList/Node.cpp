#include<iostream>
using namespace std;

class Node{
    int data;
    Node*next;
    public:
        Node(int element){
            data=element;
            next = NULL;
        }
};