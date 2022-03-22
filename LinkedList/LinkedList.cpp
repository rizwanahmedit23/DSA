#include"Node.cpp"
class Pair{
    Node*head;
    Node*tail;
};
Pair *reverseLinkedListPair(Node* head){
    if(head == NULL || head->next == NULL){
        Pair ans;
        ans.head=head;
        ans.tail=head;
        return ans;
    }
    Pair smallAns = reverseLinkedListPair(head->next);
    smallAns.tail->next=head;
    head->next = NULL;
    
    Pair ans;
    ans.head=smallAns.head;
    ans.tail=head;
    return ans;
}
Node *reverseLinkedListDoubleNode(Node* head){
    Pair ans = reverseLinkedListPair(head);
    return ans.head;
}
Node* takeInpurBetter(){
    int element;
    cin>>element;
    Node*tail = head;
    while(element!=-1){
        Node* newNode=new Node(element);
        if(head == NULL){
            head = newNode;
            tail=head;
        }
        else{
            tail->next= newNode;
            tail= tail->next;
        }
        cin>>element;
    }
    return head;
}
Node* insertNode(Node*head,int i, int data){
    Node*newNode = new Node(data);
    if(i==0){
        newNode->next = head;
        head = newNode;
        return head;
    }
    int count = 0;
    Node*temp = head;
    while(count count<i-1){
        temp = temp -> next;
        count++;
    if(temp!=NULL){
        newNode-next = temp -> next;
        temp-next = newNode;
    }
    return head;
}

