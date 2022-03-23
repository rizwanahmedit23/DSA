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
#include<utility>
#include<climits>
class Package{
    public:
    bool isBST;
    int maximum;
    int minimum;
    int largestBST;
    Package(bool isBST, int maximum, int minimum, int largestBST){
        this->isBST = isBST;
        this->maximum = maximum;
        this->minimum = minimum;
        this->largestBST = largestBST;
    }
};
Package helper(BinaryTreeNode<int> *root) {
    // Write your code here
	if(root==NULL){
        Package ans(true, INT_MIN, INT_MAX, 0);
    	return ans;
    }
	Package leftAns = helper(root->left);
	Package rightAns = helper(root->right);
    bool isBST = root->data > leftAns.maximum && root->data <= rightAns.minimum && leftAns.isBST && rightAns.isBST;

    int largest = max(root->data, max(leftAns.maximum, rightAns.maximum));
    int smallest =min(root->data, min (leftAns.minimum, rightAns.minimum));
    pair<int, int> smallAns(largest, smallest);
    int largestBST;
    if(isBST){
    	largestBST = 1 + max(leftAns.largestBST, rightAns.largestBST);        
    }
    else{
    	largestBST = max(leftAns.largestBST, rightAns.largestBST);
    }
    Package ans(isBST,largest, smallest, largestBST);
    return ans;
	// if(root->left == NULL && root->right == NULL){
	// 	pair<bool, int> ans(true, 1);	
	// return ans;
	// }
	// pair<bool,int> leftAns = helper(root->left);
	// pair<bool,int> rightAns = helper(root->right);
	// if(leftAns.first && rightAns.first){
	// if(root->left != NULL && root->right !=NULL){
	// if(root->data > root->left->data && root->data <= root->right->data){
	// pair<bool, int> ans(true, 1+max(leftAns.second, rightAns.second) );
	// return ans;
	// }
	// else{
	// pair<bool, int > ans(false, max(leftAns.second, rightAns.second) );
	// return ans;                
	// }
	// }
	// if(root->left != NULL){
	// if(root->data > root->left->data){
	// pair<bool, int > ans (true, 1+leftAns.second );
	// return ans;
	// }
	// else{
	// pair<bool, int > ans (false, leftAns.second );
	// return ans;
	// }
	// }
	// if(root->right != NULL){
	// if(root->data <= root->right->data){
	// pair<bool, int > ans (true, 1+rightAns.second );
	// return ans;
	// }
	// else{
	// pair<bool, int > ans (false, rightAns.second );
	// return ans;
	// }
	// }
	// }
	// if(!leftAns.first || !rightAns.first){
	// 	pair<bool, int > ans(false, max(leftAns.second, rightAns.second) );
	// return ans;                
	// }
}
int largestBSTSubtree(BinaryTreeNode<int> *root) {
    Package ans = helper(root);	
	return ans.largestBST;
}