/************************************************************

    Following is the Binary Tree node structure

    template <typename T>
    class BinaryTreeNode
    {
        public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data)
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

void insertDuplicateNode(BinaryTreeNode<int> *root) {
    // Write your code here
    if(root == NULL)	return;
    
    BinaryTreeNode<int> * duplicateNode = new BinaryTreeNode<int>(root->data);
    duplicateNode->left = root->left;
    root->left = duplicateNode;
    
    insertDuplicateNode(duplicateNode->left);
    insertDuplicateNode(root->right);
}