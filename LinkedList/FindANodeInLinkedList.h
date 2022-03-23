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
int findNode(Node *head, int key, int currIndex){
    if(head==NULL){
        return -1;
    }
    if(head->data == key){
        return currIndex;
    }
    else{
        currIndex++;
        int smallOutput=findNode(head->next, key, currIndex);
        return smallOutput;
    }
}
int findNode(Node *head, int n){
    // Write your code here.
    //Iterative
    int pos=0;
    Node* temp=head;
    while(temp!=NULL){
        if(temp->data==n)
            return pos;
        temp=temp->next;
        pos++;
    }
    return -1;
    
    //RECURSIVE
    // return findNode(head, n, 0);
}