#include <iostream>
class Node
{
public:
	int data;
	Node *next;
	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};

using namespace std;
Node *bubbleSort(Node *head)
{
	// Write your code here
    if(head == NULL || head->next==NULL){
        return head;
    }
    Node *temp=head;
    Node *p=head;
    int l=0;
    while(temp!=NULL){
        l++;
        temp=temp->next;
    }
    temp=head;
   	
    while(--l){
        while(temp->next!=NULL){
            if(temp->data > temp->next->data){
                if(temp==head){
                    p=temp->next;
                    temp->next=temp->next->next;
                    p->next=temp;
                    head=p;
                }
                else{
                    p->next=temp->next;
                    temp->next=temp->next->next;
                    p->next->next=temp;
                    p=p->next;
                }
            }
            else{

                if(temp==head)	temp=temp->next;
                else{
                    temp=temp->next;
                    p=p->next;
                }
            }
            if(temp->next==NULL)	temp=head;
        }
    }
    return head;
}
Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newnode = new Node(data);
		if (head == NULL)
		{
			head = newnode;
			tail = newnode;
		}
		else
		{
			tail->next = newnode;
			tail = newnode;
		}
		cin >> data;
	}
	return head;
}
void print(Node *head)
{
	Node *temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}
int main()
{
	Node *head = takeinput();
	head = bubbleSort(head);
	print(head);
}