#include<iostream>
using namespace std;
class Node {
    public:
        int data;
        Node*next;
        Node(int val){
            data=val;
            next=NULL;
        }
};
Node*head=NULL;
int getvalue(){
    int val;
    cout<<"Enter value to be inserted"<<endl;
    cin>>val;
    return val;
}
void insertAtHead(){
    int val=getvalue();
    Node*n =new Node(val);
    if(head==NULL){
        head=n;
        return;
    }
        n->next=head;
        head=n;
    return;
}
void insertAtTail(){
    int val=getvalue(); 
    Node*n=new Node(val);
    Node*temp=head;
    if(head==NULL){
        head=n;
        return;
    }
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
}
void insertAtMiddle(int i){
    int val=getvalue();
    Node* n=new Node(val);
    if(head==NULL){
        head=n;
    }
    else{
        Node* temp=head;
        for(int j=0;j<i-2;j++){
            temp=temp->next;
        }
        n->next=temp->next;
        temp->next=n;
    }
    return;
}

void deletion(){
    int val;
    cout<<"Enter value to be deleted"<<endl;
    cin>>val;

    if(head==NULL){
        cout<<"List is empty"<<endl;
        return;
    }
    if(head->data==val){
        head=head->next;
        return;
    }
    Node*temp=head;
    while(temp->next!=NULL && temp->next->data!=val){
        temp=temp->next;
    }
    if(temp->next==NULL){
        cout<<"Item not found"<<endl;
        return;
    }
    temp->next=temp->next->next;

}
void display(){
    if(head==NULL)
        return;
    Node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}
void search(){
    if(head==NULL)
        return;
    int key;
    cout<<"Enter item to be searched"<<endl;
    cin>>key;
    Node*temp=head;
    while(temp!=NULL){
        if(temp->data==key){
            cout<<"Item found"<<endl;
        }
        temp=temp->next;
    }
}
Node* ReverseRecursive(Node*p){
    if (p == NULL || p->next == NULL)
        return p;
    Node* newhead=ReverseRecursive(p->next);
    p->next->next=p;
    p->next=NULL;
    return newhead;
}
Node* ReverseIterative(){
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node *prev=NULL;
    Node*current=head;
    Node*next;

    while(current!=NULL){
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    return prev;
}
Node* reversek(Node*p,int k){
    Node*prev=NULL;
    Node*current=p;
    Node*next;
    int count=0;
    while(current!=NULL && count<k){
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
        count++;
    }
    if(next!=NULL){
        p->next=reversek(next,k);
    }
    return prev;
}
bool detectcycle(){
    Node* hare=head;
    Node* turtle=head;

    while(hare->next!=NULL && hare->next->next!=NULL){
        hare=hare->next->next;
        turtle=turtle->next;

        if(hare==turtle){
            return true;
        }
    }
    return false;
}
void makecycle(int pos){
    Node*posptr=head;
    Node*lastptr=head;
    int count=0;
    while(lastptr->next!=NULL){
        lastptr=lastptr->next;
        if(count<3){
            posptr=posptr->next;
            count++;
        }
    }
    lastptr->next=posptr;
}
int main(){
    int ch;
    cout<<"Menu Options"<<endl;
    while(1){
    cout<<"1.InsertAtHead 2.InsertAtTail 3.InsertinMiddle 4.Delete 5.Display ";
    cout<<"6.Search 7.Reverse recursive 8.Reverse iterative 9.Reverse k nodes ";
    cout<<"10.Make cycle 11.Detect Cycle"<<endl;
    
    cin >> ch;
    switch (ch){
        case 1:
            insertAtHead();
            break;
        case 2:
            insertAtTail();
            break;
        case 3:
            int i;
            cout<< "Inter position to insert at:";
            cin>>i;
            insertAtMiddle(i);
            break;
        case 4:
            deletion();
            break;
        case 5:
            display();
            break;
        case 6:
            search();
            break;
        case 7:
            head=ReverseRecursive(head);
            break;
        case 8:
            head=ReverseIterative();
            break;
        case 9:
            int k;
            cout<< "Enter k value:"<<endl;
            cin>>k;
            head=reversek(head,k);
            break;
        case 10:
            int p;
            cout<<"Enter the position to make cycle"<<endl;
            cin>>p;
            makecycle(p);
            break;
        case 11:
            detectcycle();
            break;
        default:
        exit(0);
            break;
        }
    }
}