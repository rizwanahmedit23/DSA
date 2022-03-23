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
class Pair{
    public:
    int height;
    bool isBalanced;
    Pair(){}
    Pair(int height, bool isBalanced){
        this->height = height;
        this->isBalanced = isBalanced;
    }
};
Pair isBalancedHelper(BinaryTreeNode<int> *root){
    if(root==NULL){
        Pair Ans(0,true);
        return Ans;
    }	
	Pair leftAns = isBalancedHelper(root->left);
    Pair rightAns = isBalancedHelper(root->right);
    int height = max(leftAns.height , rightAns.height) + 1;
	Pair Ans(height, false);

    if(leftAns.isBalanced==false || rightAns.isBalanced==false)	return Ans;
    int absoluteDifference = leftAns.height-rightAns.height;
    // if(absoluteDifference == -1)	absoluteDifference*=-1;
    if(absoluteDifference <=1 && absoluteDifference >=-1)
        Ans.isBalanced = true;
	return Ans;    
}
bool isBalanced(BinaryTreeNode<int> *root) {
	// Write your code here
    Pair Ans = isBalancedHelper(root);
    return Ans.isBalanced;
}