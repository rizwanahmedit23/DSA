/**********
 * Following is the Node class that is already written.
 
class Node{
public:
    int data;
    Node *next;
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};
 
*********/
Node* reverseLL(Node *head){
    if(head==NULL || head->next==NULL)	return head;
    
    Node *temp;
    temp = reverseLL(head->next);
    head->next->next = head;
    head->next=NULL;
    head=temp;
    return head;
}
Node* NextLargeNumber(Node *head) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input is handled automatically.
     */
    if(head==NULL)	return head;
    head = reverseLL(head);
    Node *temp = head;
    Node *tail=head;
    int carry=1;
    while(temp!=NULL){
        if(temp->data + carry >9 ){
            temp->data=0;
            carry=1;
        }
        else{
            temp->data+=carry;
            carry=0;
        }
        if(temp->next!=NULL){
            tail=tail->next;
        }
        temp=temp->next;
    }
    if(carry==1){
        Node *newNode = new Node(1);
        tail->next=newNode;
    }
    head=reverseLL(head);
    return head;
}


