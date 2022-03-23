/**********************************************************

	Following is the Binary Tree Node class structure

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
	
***********************************************************/
#include<stack>
int noOfNodes(BinaryTreeNode<int> *root){
    if(root== NULL)	return 0;
    return 1+noOfNodes(root->left)+noOfNodes(root->right);
}
void printNodesSumToS(BinaryTreeNode<int> *root, int s) {
    // Write your code here
    stack<BinaryTreeNode<int> *> s1;
    stack<BinaryTreeNode<int> *> s2;
    
    BinaryTreeNode<int> *temp = root;
    while(temp != NULL){
		s1.push(temp);
        temp=temp->left;
    }
	temp = root;
    while(temp != NULL){
		s2.push(temp);
        temp = temp->right;
    }
    int count = 0;
    int size = noOfNodes(root);
    while(count<size-1){
        if(s1.top()->data + s2.top()->data == s){
            BinaryTreeNode<int> * node1 = s1.top();s1.pop();count++;
            BinaryTreeNode<int> * node2 = s2.top();s2.pop();count++;
            cout<< min(node1->data, node2->data) <<" "<< max(node1->data, node2->data)<<endl;
            temp = node1->right;
            while(temp!=NULL){
                s1.push(temp);
            	temp = temp->left;
            }
            temp = node2->left;
            while(temp!=NULL){
                s1.push(temp);
            	temp = temp->right;
            }
        }
        else if(s1.top()->data + s2.top()->data < s){
			BinaryTreeNode<int> * node1 = s1.top();
            s1.pop();
            temp = node1->right;
            while(temp!=NULL){
                s1.push(temp);
            	temp = temp->left;
            }
            count ++;
        }
        else{
			BinaryTreeNode<int> * node1 = s2.top();
            s2.pop();
            temp = node1->left;
            while(temp!=NULL){
                s1.push(temp);
            	temp = temp->right;
            }
            count ++;
        }
    }
}