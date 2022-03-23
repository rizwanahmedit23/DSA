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
// int sum(BinaryTreeNode<int> *root){
//     if(root==NULL)	return 0;
    
//     int sumL = sum(root->left);
//     int sumR = sum(root->right);
// 	return root->data + sumL + sumR;
// }
int replaceAndReturnSum(BinaryTreeNode<int> *root, int sum) {
    if(root==NULL)	return 0;
    int sumR = replaceAndReturnSum(root->right, sum);
    int rootData = root->data;
    root->data += sumR + sum;
    int sumL = replaceAndReturnSum(root->left, rootData + sum + sumR);
	return rootData + sumR + sumL;
}
void replaceWithLargerNodesSum(BinaryTreeNode<int> *root) {
    // Write your code here
    replaceAndReturnSum(root, 0);    
}