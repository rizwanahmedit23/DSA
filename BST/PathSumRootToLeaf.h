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
#include<vector>
void rootToLeafPathSumToK(BinaryTreeNode<int> *root, int k, vector<int>& v){
    if(root==NULL){
		return;
    }
    v.push_back(root->data);
    if(root->data == k){
        if(root->right == NULL && root->left == NULL){
			for(int i=0;i<v.size();i++){
                cout<< v[i]<<" ";
            }
            cout<<endl;
        }
        v.pop_back();
        return;
    }
	int newK = k - root->data;
    if(newK < 0){
		v.pop_back();
        return;
    }
    if(newK > 0){
        // v.push_back(root->data);
        // if(newK < root->data){
        // vector<int> v2 = v;
			rootToLeafPathSumToK(root->left, newK, v);
        // }
        // if(newK >= root->data){
			// rootToLeafPathSumToK(root->left, newK, v);
            rootToLeafPathSumToK(root->right, newK, v);
        // }
        v.pop_back();
        return;
    }
}
void rootToLeafPathsSumToK(BinaryTreeNode<int> *root, int k) {
    // Write your code here
    vector<int> v;
    rootToLeafPathSumToK(root, k, v);
}