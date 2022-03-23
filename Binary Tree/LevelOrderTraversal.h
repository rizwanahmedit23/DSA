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

void printLevelWise(BinaryTreeNode<int> *root) {
    // Write your code here
    if(root==NULL)	return;
    
    cout<< root->data<<endl;
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(!pendingNodes.empty()){
        int n = pendingNodes.size();
        for(int i=0;i<n;i++){
            BinaryTreeNode<int> * front = pendingNodes.front();
            pendingNodes.pop();
            if(front->left!=NULL){
                cout<< front->left->data<<" ";
                pendingNodes.push(front->left);
            }
            if(front->right!=NULL){
                cout<< front->right->data<<" ";
                pendingNodes.push(front->right);
            }
        }
        cout<<endl;
    }
    return;
}