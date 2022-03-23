/****************************************************************
 
    Following is the class structure of the Node class:

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

*****************************************************************/
int length(Node*head){
    int len=0;
    while(head!=NULL){
        len++;
        head=head->next;
    }
    return len;
}
Node *appendLastNToFirst(Node *head, int n)
{
// Write your code here
// RECURSICE
// Some mistakes needs to be rectified...
    
//     if(head==NULL || n==0){
//         return head;
//     }
// 	head->next=appendLastNToFirst(head->next,n);
//     Node*temp=head;
//     while(n--){
//         temp=temp->next;
//     }
//     Node*NewHead=head->next;
//     Node*NewTemp=temp->next;
    
//     temp->next=head;
//     head->next=NewTemp;
    
//     return NewHead;
// }
	//ITERATIVE
	//when 0 or 1 node
    if(head==NULL || head->next==NULL || n==0)
        return head;
    
    int size= length(head);
    Node*temp=head;
    int x=size-n-1;
    while(x--){
        temp=temp->next;
    }
    
    Node*prevHead=head;
    
    head=temp->next;
    Node*last=temp;
    
    while(temp->next!=NULL){
        temp=temp->next;
    }
    
    last->next=NULL;
    temp->next=prevHead;
    
    return head;
}


s