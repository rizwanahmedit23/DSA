
/*********************************************************
 
    // Following is the node structure

    class Node {
    public:
        int data;
        Node * next;
        Node(int data){
            this -> data = data;
            this -> next = NULL;
        }
    
        ~Node() {
            if(next) {
                delete next;
            }
        }
    };

*********************************************************/

void deleteAlternateNodes(Node *head) {
    //Write your code here
    Node *curr = head;
    while(curr!=NULL && curr->next!=NULL){
        Node *temp=curr->next;
        curr->next=curr->next->next;
        temp->next=NULL;	//or else destructor when called will delete the remaining nodes.
        delete temp;		
        curr=curr->next;
    }
}