/**********************************************************

	Following are the Binary Tree Node class structure and
	the Node class structure

	template <typename T>
	class BinaryTreeNode {
    	public: 
    	T data;
    	BinaryTreeNode<T> *left;
    	BinaryTreeNode<T> *right;

    	BinaryTreeNode(T data) {
        	this->data = data;
        	left = NULL;
        	right = NULL;
    	}
	};

	template <typename T>
	class Node {
		public:
    	T data;
    	Node<T> *next;
    	Node(T data) {
        	this->data=data;
        	this->next=NULL;
    	}
	};

***********************************************************/
Node<int>* takeInputLL(Node<int>* head, int data){
    Node<int>* newNode = new Node<int>(data);
    if(head==NULL){
        head=newNode;
        return head;
    }
    Node<int>* temp = head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newNode;
    return head;
}
vector<Node<int>*> constructLinkedListForEachLevel(BinaryTreeNode<int> *root) {
    // Write your code here  
    vector<Node<int>*> ans;
    if(root == NULL){
    	return ans;    
    }
    Node<int>* head = new Node<int>(root->data);
    ans.push_back(head);
	queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    
    while(!pendingNodes.empty()){
        int size = pendingNodes.size();
        head=NULL;
        Node<int>* tail = NULL;
        for(int i=0;i<size;i++){
            BinaryTreeNode<int> *front = pendingNodes.front();
        	pendingNodes.pop();
            if(front->left!=NULL){
                pendingNodes.push(front->left);
                // head = takeInputLL(head, front->left->data);
            	Node<int>* newNode = new Node<int>(front->left->data);                
            	if(head==NULL){
                	head=tail=newNode;
                }
                else{
                    tail->next=newNode;
                	tail=tail->next;
                }
            }
            if(front->right!=NULL){
                Node<int>* newNode = new Node<int>(front->right->data);
                if(head==NULL){
                	head=tail=newNode;
                }
                else{
                    tail->next=newNode;
                	tail=tail->next;
                }
                pendingNodes.push(front->right);
                // head =  takeInputLL(head, front->right->data);
            }
    	}
        if(head!=NULL)
        	ans.push_back(head);
    }
	return ans;
}