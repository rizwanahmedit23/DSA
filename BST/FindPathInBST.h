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

vector<int>* getPath(BinaryTreeNode<int> *root , int data) {
	// Write your code here
    vector<int>* ans = new vector<int>();
    if(root==NULL)	return ans;
    else if(root->data == data){
        ans->push_back(root->data);
        return ans;
    }
    else{
        if(data<root->data){
            vector<int>* leftAns = getPath(root->left, data);
            if(leftAns->size() != 0){
                leftAns->push_back(root->data);
                return leftAns;
            }
            return ans;
        }
        else{
            vector<int>* rightAns = getPath(root->right, data);
            if(rightAns->size() != 0){
                rightAns->push_back(root->data);
                return rightAns;
            }
            return ans;
    	}
    }
}