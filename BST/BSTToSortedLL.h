/**********************************************************

	Following are the Binary Tree Node class structure and the 
	Node class structure

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
 	class Node{
    	public:
    	T data;
    	Node<T> *next;
    
    	Node(T data) {
        	this->data = data;
        	this->next = NULL;
    	}
 	};

***********************************************************/
#include<utility>
pair<Node<int>*,Node<int>*> constructLinkedListhelper(BinaryTreeNode<int>* root) {
	// Write your code here
    if(root == NULL){
        pair<Node<int>*,Node<int>*> ans;
        ans.first = NULL;
        ans.second = NULL;
        return ans;
    }
    pair<Node<int>*,Node<int>*> leftAns = constructLinkedListhelper(root->left);
    
    Node<int>* newNode = new Node<int>(root->data);
    Node<int>* head,*tail;
    if(leftAns.first ==NULL){
        head = newNode; 
    }
    else{
        head = leftAns.first;
        leftAns.second->next = newNode;
    }
    tail = newNode;
    
    pair<Node<int>*,Node<int>*> rightAns = constructLinkedListhelper(root->right);
    if(rightAns.first != NULL){
		tail->next = rightAns.first;
        tail=rightAns.second;
    }
    
    pair<Node<int>*,Node<int>*> ans;
    ans.first = head;
    ans.second = tail;
    return ans;   
}
Node<int>* constructLinkedList(BinaryTreeNode<int>* root){
	pair<Node<int>*,Node<int>*> ans = constructLinkedListhelper(root);
	return ans.first;
}