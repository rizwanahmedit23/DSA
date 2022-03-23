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
#include <vector>
#include<algorithm>
void convertToArray(BinaryTreeNode<int> * root, vector<int>& arr){
    if(root==NULL){
        return;
    }
    arr.push_back(root->data);
    convertToArray(root->left, arr);
    convertToArray(root->right, arr);
    return;
}
void pairSum(BinaryTreeNode<int> *root, int sum) {
    // Write your code here
    vector<int> arr;
    convertToArray(root, arr);
    sort(arr.begin(), arr.end());
    int i = 0, j=arr.size() - 1;
	while(i<j){
        if( arr[i] + arr[j] == sum){
            cout<< min(arr[i], arr[j])<<" "<<max(arr[i], arr[j])<<endl;
            i++;j--;
        }
        else if (arr[i] + arr[j] < sum){
            i++;
        }
        else {
            j--;
        }
    }
}