#include<iostream>
#include<queue>
using namespace std;
#include"BinaryTreeNode.h"
void print(BinaryTreeNode<int>* root){
    if(root==NULL){
      return;
    }
    cout<< root->data<<":";
    if(root->left !=NULL){
        cout<<"L"<<root->left->data;
    }
    if(root->right !=NULL){
        cout<<"R"<<root->right->data;
    }
    cout<<endl;
    print(root->left);
    print(root->right);
    return;
}
BinaryTreeNode<int>* takeInput(){
    int data;
    cout<<"Enter data"<<endl;
    cin>>data;

    if(data == -1)
        return NULL;
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(data);
    root->left = takeInput();
    root->right = takeInput();

    return root;
}
BinaryTreeNode<int>* takeInputLevelWise(){
    int rootData;
    cout<<"Enter root data"<<endl;
    cin>>rootData;
    if(rootData == -1){
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size()!=0){
        BinaryTreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        int childData;
        cout<<"Enter the left child of:"<<front->data<<endl;
        cin>>childData;

        if(childData!=-1){
            BinaryTreeNode<int>* child = new BinaryTreeNode<int>(childData);
            front->left = child;
            pendingNodes.push(child);
        }
        cout<<"Enter the right child of:"<<front->data<<endl;
        cin>>childData;

        if(childData != -1){
            BinaryTreeNode<int>* child = new BinaryTreeNode<int>(childData);
            front->right = child;
            pendingNodes.push(child);
        }
    }    
    return root;
}
void printLevelWise(BinaryTreeNode<int> *root) {
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    
    while(!pendingNodes.empty()){
        BinaryTreeNode<int>* front = pendingNodes.front();
    	pendingNodes.pop();
        cout<<front->data<<":";
        if(front->left==NULL)	cout<<"L:-1,";
        else{
            cout<<"L:"<<front->left->data<<",";
        	pendingNodes.push(front->left);
        }
        if(front->right==NULL)	cout<<"R:-1";
        else {
            cout<<"R:"<<front->right->data;
        	pendingNodes.push(front->right);        
        }
        cout<<endl;        
    }
}
int count(BinaryTreeNode<int>*root){
    //wrong, if tree has one child then
    //this will caude error as base case will be false, thus 
    //when the last statement of this fnc will execute 
    //it is calling recursion on the null child
    //which does not has a stopping base case
    // if(root->left==NULL && root->right==NULL){
    //     return 1;
    // }
    // correct 
    if(root == NULL){
        return 0;
    }
    return 1+count(root->left)+count(root->right);
}
void mirrorBinaryTree(BinaryTreeNode<int>* root) {
    // Write your code here
    if(root==NULL) return;
    
    mirrorBinaryTree(root->left);
    mirrorBinaryTree(root->right);
    
    BinaryTreeNode<int>* temp=root->left;
    root->left = root->right;
    root->right = temp;
}
void inOrder(BinaryTreeNode<int>* root){
    if(root==NULL)  return;
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
    return;
}
#include<climits>
int minimum(BinaryTreeNode<int>*root){
    if(root==NULL)  return INT_MAX;
    return min(root->data, min(minimum(root->left), minimum(root->right)));
}
int maximum(BinaryTreeNode<int>*root){
    if(root==NULL)  return INT_MIN;
    return max(root->data, max(maximum(root->left), maximum(root->right)));
}
bool isBST(BinaryTreeNode<int> *root){
    if(root==NULL)  {
        return true;
    }
    int leftMax = maximum(root->left);
    int rightMin = minimum(root->right);
    bool output = (root->data > leftMax) && (root->data<=rightMin) && isBST(root->left) && isBST(root->right);
    return output;
}
class isBSTreturn{
    public:
        bool isBST;
        int minimum;
        int maximum;
};
isBSTreturn isBST2helper(BinaryTreeNode<int>* root){
    if(root == NULL){
        isBSTreturn ans;
        ans.isBST = true;
        ans.maximum = INT_MIN;
        ans.minimum = INT_MAX;
        return ans; 
    }
    isBSTreturn leftAns = isBST2helper(root->left);
    isBSTreturn rightAns = isBST2helper(root->right);
    isBSTreturn ans;
    ans.isBST = (root->data > leftAns.maximum) && (root->data<=rightAns.minimum) && leftAns.isBST && rightAns.isBST;
    ans.maximum = max (root->data, max(leftAns.maximum, rightAns.maximum) );
    ans.minimum = min (root->data, min(leftAns.minimum, rightAns.minimum) );
    return ans;
}
bool isBST2(BinaryTreeNode<int>* root){
    isBSTreturn ans = isBST2helper(root);
    return ans.isBST;
} 
bool isBST3(BinaryTreeNode<int>* root, int minimum = INT_MIN,int max =INT_MAX){
    
}
int main(){
    // BinaryTreeNode<int>* root = new BinaryTreeNode<int>(1);
    // BinaryTreeNode<int>* node1 = new BinaryTreeNode<int>(2);
    // BinaryTreeNode<int>* node2 = new BinaryTreeNode<int>(3);
    // 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1 
    BinaryTreeNode<int>* root = takeInputLevelWise();
    // root->left = node1;
    // root->right = node2;
    // inOrder(root);
     // cout<<"num of nodes:"<<count(root);
    cout<< isBST2(root)<<endl;
    return 0; 
}