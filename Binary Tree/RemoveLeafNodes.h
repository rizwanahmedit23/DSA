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

BinaryTreeNode<int>* removeLeafNodes(BinaryTreeNode<int> *root) {
    // Write your code here
    
    if(root->left == NULL && root->right == NULL){
        delete root;
        return NULL;
    }
	// else if(root->left == NULL){
	// root->right = removeLeafNodes(root->right);
	// }
	// else if(root->right == NULL){
	// root->left = removeLeafNodes(root->left);
	// }
	// else {
        if(root->left!=NULL)
        	root->left=removeLeafNodes(root->left);
        if(root->right!=NULL)        	
        	root->right = removeLeafNodes(root->right);
    // }
    
    return root;
}