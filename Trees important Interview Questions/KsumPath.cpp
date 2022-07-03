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

void Ksum(node* root, vector<int> &path , int &count,int k){
    if(root==NULL){
        return ;
    }
    path.push_back(root->data);
    Ksum(root->left,path,count,k);
    Ksum(root->right,path,count,k);

    int size= path.size();
    int sum=0;
    for(int i=size-1;i>=0;i--){
        sum+=path[i];
        if(sum==k){
            count++;
        }
    }
    path.pop_back();

}


int main(){
    node* root = NULL;
    root = buildTree(root);
    vector<int> ans;
    int count=0;
    int k=3;
    Ksum(root,ans,count,k);
    cout<<"Total number of paths in trees having their nodesum equal to Ksum: "<<count<<endl;
    return 0;
}