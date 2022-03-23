/**********************************************************
	Following is the Binary Tree Node class structure

	template <typename T>
	class BinaryTreeNode {
    	public : 
    	T data;
    	BinaryTreeNode<T> *left;
    	BinaryTreeNode<T> *right;

    	BinaryTreeNode(T data) {
        	this -> data = data;
        	left = NULL;
        	right = NULL;
    	}
	};

***********************************************************/
#include<stack>
void zigZagOrder(BinaryTreeNode<int> *root) {
    // Write your code here
    if(root==NULL)	return;
    stack<BinaryTreeNode<int> *> pendingNodes;
    cout<<root->data<<endl;
    pendingNodes.push(root);
    bool checkOddLevel = false;
    while(!pendingNodes.empty()){
        int size = pendingNodes.size();
        vector<BinaryTreeNode<int>*> temp;
        for(int i=0;i<size;i++){
            BinaryTreeNode<int> *front = pendingNodes.top();
            pendingNodes.pop();
            if(!checkOddLevel){
                if(front->right !=NULL){
                    cout<<front->right->data<<" ";
                    temp.push_back(front->right);
                    // pendingNodes.push(front->right);
                }
                if(front->left !=NULL){
                    cout<<front->left->data<<" ";
                    temp.push_back(front->left);
                    // pendingNodes.push(front->left);
                }
            }
            else{
                if(front->left !=NULL){
                    cout<<front->left->data<<" ";
                    temp.push_back(front->left);                    
                    // pendingNodes.push(front->left);
                }
                if(front->right !=NULL){
                    cout<<front->right->data<<" ";
                    temp.push_back(front->right);
                    // pendingNodes.push(front->right);
                }
            }
        }
        for(int i=0;i<temp.size();i++){
            pendingNodes.push(temp[i]);
        }
        cout<<endl;
        checkOddLevel = !checkOddLevel;
    }
    
}