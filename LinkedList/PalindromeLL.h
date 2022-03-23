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
bool isPalindrome(Node *head, int size)
{
    //Write your code here
    if(size<=1)
        return true;
    
    Node* tail=head;
    int x=size-1;
    while(x--){
        tail=tail->next;
    }
    if(head->data == tail->data)
        return isPalindrome(head->next,size-2);
    else 
        return false;
}
bool isPalindrome(Node *head){
    int size=length(head);
    return isPalindrome(head, size);
}