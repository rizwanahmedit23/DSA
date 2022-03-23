/************************************************************
 
    Following is the structure for the TreeNode class

    template <typename T>
    class TreeNode {
     public:
        T data;
        vector<TreeNode<T>*> children;
    
        TreeNode(T data) {
            this->data = data;
        }
    
        ~TreeNode() {
            for (int i = 0; i < children.size(); i++) {
                delete children[i];
            }
        }
    };

************************************************************/

TreeNode<int>* getNextLargerElement(TreeNode<int>* root, int x) {
    // Write your code here
    TreeNode<int>* ans;
    if(root->data>x)	ans = root;
	else ans=NULL;
    
    for(int i=0;i<root->children.size();i++){
		TreeNode<int>* smallAns = getNextLargerElement(root->children[i], x);
		if(smallAns!=NULL){
            if(ans==NULL)	ans=smallAns;
            else{
                if(smallAns->data<ans->data)	ans=smallAns;
            }
        }
    }
    
    return ans;
}