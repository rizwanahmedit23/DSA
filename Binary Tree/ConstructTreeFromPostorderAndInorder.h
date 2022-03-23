/***********************************************************
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

BinaryTreeNode<int>* buildTree(int *preorder, int *inorder,int preS, int preE, int inS, int inE){
    // Write your code here
    if(preS > preE || inS > inE)	return NULL;
    int lpreS = preS+1;
    int linS = inS + 0;
    int linE;
    int rootData = preorder[preS]; 
    int i=inS;
    while(inorder[i]!=rootData){
		i++;
    }
    linE = i-1;
    int lpreE = lpreS + (linE - linS);
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(preorder[preS]);
    int lprel = lpreS + lpreE;
    int linl = linS + linE;
    root->left = buildTree(preorder, inorder, lpreS, lpreE, linS, linE);
    int rinS = linE + 2;
    int rpreS = lpreE + 1; 
    int rpreE = preE;
    int rinE = rpreE;//inE
	root->right = buildTree(preorder, inorder, rpreS, rpreE, rinS, rinE);
    return root;
}
BinaryTreeNode<int>* buildTree(int *preorder, int preLength, int *inorder, int inLength){
    return buildTree(preorder, inorder, 0, preLength-1, 0, inLength-1);
} 