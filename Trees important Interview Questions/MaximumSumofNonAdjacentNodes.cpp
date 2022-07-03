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

pair<int,int> MaximumSum(node* root){
    if(root==NULL){
        pair<int,int> p = make_pair(0,0);
        return p; 
    }    
    pair<int,int> left = MaximumSum(root->left);
    pair<int,int> right = MaximumSum(root->right);
    
    pair<int,int> result;
    result.first = root->data+left.second+right.second;
    result.second = max(left.first,left.second) + max(right.first,right.second);

    return result;
}
  




int main(){
    node* root = NULL;
    root = buildTree(root);
    pair<int,int> ans = MaximumSum(root);
    cout<<"Maximum Sum of Non Adjacent Nodes: "<<max(ans.first,ans.second)<<endl;
    return 0;
}