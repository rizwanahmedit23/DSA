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
void printElementAtDepthK(BinaryTreeNode<int> *root, int depth){
    if(root==NULL)	return;
    if(depth == 0){
        cout<< root->data<<endl;
        return;
    }
    printElementAtDepthK(root->left, depth-1);
    printElementAtDepthK(root->right, depth-1);
	return;
}
int nodesAtDistanceKHelper(BinaryTreeNode<int> *root, int node, int k){ //function returns the distance from nodeTOroot.
    if(root== NULL)	return -1;
    if(root->data == node){
        printElementAtDepthK(root, k);
        return 0;
    }
    int ld = nodesAtDistanceKHelper(root->left, node, k);
    if(ld == -1){
        int rd = nodesAtDistanceKHelper(root->right, node, k);
        if(rd == -1)	return -1;
        int D = rd + 1;
        if(D == k){
            cout<<root->data<<endl;
        	return D;
        }
        else{
            printElementAtDepthK(root->left, k-D-1);
            return D;
        }
        /*if(D > k){		// No need because U should assume that recursion will handle left subtree
			printElementAtDepthK(root->right, D-k-1);
            return D;
        }*/
    }
    int D = ld+1;
    if(D == k){
        cout<< root->data<< endl;
        return D;
    }
    /*if(D > k){
        printElementAtDepthK(root->left, D-k-1);
    	return D;
    }*/
    else{
		printElementAtDepthK(root->right, k-D-1);
        return D;
    }
}
void nodesAtDistanceK(BinaryTreeNode<int> *root, int node, int k) {
    // Write your code herez
    nodesAtDistanceKHelper(root, node, k);
}