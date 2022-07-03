#include<iostream>
#include<bits/stdc++.h>
#include<limits.h>
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







node* KthAncestor(node* root,int &k,int &nodes){
    if(root==NULL){
        return NULL;
    }
    if(root->data==nodes){
        return root;
    }
    node* leftnode = KthAncestor(root->left,k,nodes);
    node* rightnode = KthAncestor(root->right,k,nodes);

    if(leftnode != NULL && rightnode == NULL ){
        k--;
        if(k<=0){
            k=INT_MAX;
            return root;
        }
        return leftnode;
    }
    else if(leftnode == NULL && rightnode != NULL ){
           k--;
        if(k<=0){
            k=INT_MAX;
            return root;
        }
        return rightnode;
    }
    return NULL;
}

 



int main(){
    node* root = NULL;
    root = buildTree(root);
    int k=2;
    int nodes=4;
    node* ansnod = KthAncestor(root,k,nodes);
    if(ansnod==NULL){
        cout<<"NULL";
    }
    else{
        cout<<"Kth Ancestor Node: "<<ansnod->data<<endl;
    }
    return 0;
}