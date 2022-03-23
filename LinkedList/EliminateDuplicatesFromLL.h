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

Node *removeDuplicates(Node *head)
{
    //Write your code here
    if(head==NULL ||  head->next==NULL) return head;
	Node *prev,*curr;
    prev=head;
    curr=head->next;
    
    while(curr!=NULL){
        if(prev->data == curr->data){
            curr=curr->next;
            prev->next=curr;
        }
        else{
        	curr=curr->next;   
        	prev=prev->next;
        }

    }
    return head;
}