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

int getHeight(TreeNode<int>* root) {
    // Write your code here
    int height=1;
    int maxChildHeight = 0;
    for(int i=0;i<root->children.size();i++){
        maxChildHeight = max(maxChildHeight, getHeight(root->children[i]));
    }
    height += maxChildHeight;
    return height;
}