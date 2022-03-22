#include<iostream>
using namespace std;
#include "TreeNode.h"
#include<queue>
void printLevelWise(TreeNode<int>* root) {
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(!pendingNodes.empty()){
        TreeNode<int>* currNode = pendingNodes.front();
        pendingNodes.pop();
        cout<<currNode->data<<":";
        for(int i=0;i<currNode->children.size();i++){
            if(i==currNode->children.size()-1)
                cout<<currNode->children[i]->data;
            else
                cout<<currNode->children[i]->data<<",";
            pendingNodes.push(currNode->children[i]);
        }
        cout<<endl;
    }
}
void printTree(TreeNode<int>* root){
    cout<< root->data <<":";
    for(int i=0;i<root->children.size();i++){
        cout<<root->children[i]->data <<" ";
    }
    cout << endl;
    for(int i=0;i<root->children.size();i++){
        printTree(root->children[i]);
    }
    return;
}
TreeNode<int>* takeInputLevelWise(){
    int rootData;
    cout<<"Enter root data"<<endl;
    cin>> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size() != 0){
        TreeNode<int>* curr = pendingNodes.front();
        pendingNodes.pop();
        int n;
        cout<<"Enter the number of children of:"<<curr->data<<endl;
        cin>>n;
        for(int i=0;i<n;i++){
            cout<<"Enter the "<<i<<"th child of"<<curr->data<<endl;
            int data;
            cin>>data;
            TreeNode<int>* newNode = new TreeNode<int>(data);
            pendingNodes.push(newNode);
            curr->children.push_back(newNode);
        }
    }
    return root;
}
TreeNode<int>* takeInput(){
    int rootData;
    cout<<"Enter data"<<endl;
    cin>> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);
    int n;
    cout<<"Enter number of children of "<<root->data<<endl;
    cin>>n;
    
    for(int i=0;i<n;i++){
        // root->children.push_back(takeInput());
        TreeNode<int>* smallRoot = takeInput();
        root->children.push_back(smallRoot);
    }
    return root;
}
int numNodes(TreeNode<int>* root){
    int ans=1;
    for(int i=0;i<root->children.size();i++){
        ans+=numNodes(root->children[i]);
    }
    return ans;
}
TreeNode<int>* maxDataNode(TreeNode<int>* root) {
    TreeNode<int>* treeMaxNode = root;
    for(int i=0;i<root->children.size();i++){
        TreeNode<int>* smallMax = maxDataNode(root->children[i]);
		if(treeMaxNode->data<smallMax->data){
			treeMaxNode=smallMax;
        }
    }
    
    return treeMaxNode;
}
int getLeafNodeCount(TreeNode<int>* root) {
    // Write your code here
    if(root->children.size()==0)
        return 1;
    int ans=0;
    for(int i=0;i<root->children.size();i++){
		ans+=getLeafNodeCount(root->children[i]);
    }
    return ans;
}
void preorder(TreeNode<int>*root){
    if(root==NULL)     //Not a base case, just an
        return;        //edge case.
    cout<<root->data<<endl;
    for(int i=0;i<root->children.size();i++){
        preorder(root->children[i]);
    }
}
void postorder(TreeNode<int>*root){
    if(root==NULL)     //Not a base case, just an
        return;        //edge case.
    for(int i=0;i<root->children.size();i++){
        postorder(root->children[i]);
    }
    cout<<root->data<<endl;

}
int main(){
    // TreeNode<int> *root = new TreeNode<int>(1);
    // TreeNode<int> *node1 = new TreeNode<int>(2);
    // TreeNode<int> *node2 = new TreeNode<int>(3);
    // root->children.push_back(node1);
    // root->children.push_back(node2);
    TreeNode<int>*root = takeInputLevelWise();
    postorder(root);
}

