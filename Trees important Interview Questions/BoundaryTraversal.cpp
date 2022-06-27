#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class node{
    public:
        int data;
        node* left;
        node* right;

    node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node* buildTree(node* root){
    cout<<"Enter the data: ";
    int data;
    cin>>data;
    root=new node(data);

    if(data==-1){
        return NULL;
    }

    cout<<"Enter data for inserting in left "<<data;
    cout<<endl;
    root->left=buildTree(root->left);
    
    cout<<"Enter data for inserting in right "<<data;
    cout<<endl;
    root->right=buildTree(root->right);
    
    return root;

}

void leftpart(node* root,vector<int> &ans){
    if(root==NULL || (root->left==NULL && root->right==NULL)){
        return ;
    }
    if(root->left){
        leftpart(root->left,ans);
    }
    else{
        leftpart(root->right,ans);
    }
    ans.push_back(root->data);
}






void leafpart(node* root,vector<int> &ans){
    if(root==NULL){
        return;
    }
    if(root->left==NULL && root->right==NULL){
        ans.push_back(root->data);
    }
    leafpart(root->left,ans);
    leafpart(root->right,ans);
}








void reverserightpart(node* root,vector<int> &ans){
    if(root==NULL || (root->left==NULL && root->right==NULL)){
        return;
    }

    if(root->right){
        reverserightpart(root->right,ans);
    }
    else{
        reverserightpart(root->left,ans);
    }
    ans.push_back(root->data);
}






void BoundaryTraversal(node* root){
    vector<int> ans;
    ans.push_back(root->data);

    leftpart(root->left,ans);
    leafpart(root->left,ans);
    leafpart(root->right,ans);
    reverserightpart(root->right,ans);

    for(int i:ans){
        cout<<i<<",";
    }
}








int main(){
    node* root = NULL;
    root = buildTree(root);
    BoundaryTraversal(root);
    return 0;

}