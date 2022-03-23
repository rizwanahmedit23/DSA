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
    // 
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    
    while(!pendingNodes.empty()){
        BinaryTreeNode<int>* front = pendingNodes.front();
    	pendingNodes.pop();
        cout<<front->data<<":";
        if(front->left==NULL)	cout<<"L:-1,";
        else{
            cout<<"L:"<<front->left->data<<",";
        	pendingNodes.push(front->left);
        }
        if(front->right==NULL)	cout<<"R:-1";
        else {
            cout<<"R:"<<front->right->data;
        	pendingNodes.push(front->right);        
        }
        cout<<endl;        
    }
}