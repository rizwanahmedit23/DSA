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
void replaceWithDepthValueHelper(TreeNode<int>* root, int depth) {
    // Write your code here
    root->data=depth;
    for(int i=0;i<root->children.size();i++){
        replaceWithDepthValueHelper(root->children[i], depth+1);
        // root->children[i]->data=1;
    }
    return ;
}
void replaceWithDepthValue(TreeNode<int>* root) {
    replaceWithDepthValueHelper(root,0);
}

