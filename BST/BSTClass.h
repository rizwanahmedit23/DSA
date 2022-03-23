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

class BST {
    // Define the data members
    private:
    BinaryTreeNode<int>* root;
   public:
    BST() { 
        // Implement the Constructor
        root==NULL;
    }

	/*----------------- Public Functions of BST -----------------*/
	private:
    BinaryTreeNode<int>* remove(BinaryTreeNode<int>* root, int data){
        if(root==NULL)	return NULL;
        
        if( data == root->data){
            if(root->left == NULL && root->right == NULL){
                delete root;
                return NULL;
            }
            else if (root->left == NULL){
                BinaryTreeNode<int> * temp = root->right;
                root->right == NULL;
                delete root;
                return temp;
            }
            else if (root->right == NULL){
                BinaryTreeNode<int>* temp = root->left;
                root->left == NULL;
                delete root;
                return temp;
            }
            else{
                BinaryTreeNode<int>* temp = root-> right;
                while(temp -> left != NULL){
                    temp = temp-> left;
                }
                root->data = temp->data;
                root->right = remove (root->right, temp->data);
                return root;
            }
        }
        else if(data < root->data){
            root->left = remove(root->left, data);
        	return root;
        }
        else{
            
        }
    }
    public:
    void remove(int data) { 
        // Implement the remove() function 
    	root = remove(root, data);
    }
    private:
	void printInOrder(BinaryTreeNode<int>* root){
        if(root==NULL)	return;
        
        cout<<root->data<<":";
        if(root->left!=NULL){
            cout<<"L:"<<root->left->data<<",";
        }
        if(root->right!=NULL){
			cout<<"R:"<<root->right->data;
        }
        cout<<endl;
        printInOrder(root->left);
        printInOrder(root->right);
    }
        
    public:
    void print() { 
        // Implement the print() function
		printInOrder(root);
    }
	private:
    BinaryTreeNode<int>* insert(BinaryTreeNode<int>* root, int data){
        if(root == NULL){
            BinaryTreeNode<int>* newNode = new BinaryTreeNode<int>(data);
            return newNode;
        }
        
        if(data <= root->data){						// Insert in left subtree if given data is == root->data
            root->left =  insert(root->left, data); // because it is specified in the question
        }
        else
            root->right = insert(root->right, data);
        return root;
    }
    public:
    void insert(int data) { 
        // Implement the insert() function 
        root = insert(root, data);
    }
    private:
    bool search(BinaryTreeNode<int>* root, int key){
		if(root==NULL)	return false;
        
        if(key == root->data){
            return true;
        }
        
        if(key < root->data){
            return search(root->left, key);
        }
        else	return search(root->right, key);
    }
	public:
    bool search(int data) {
		// Implement the search() function
        return search(root, data);
    }
};