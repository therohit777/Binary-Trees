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


void ZigzagTraversal(node* root){
    if(root==NULL){
        return ;
    }
    
    bool flag=true;
    queue<node*> q;
    q.push(root);
    vector<int> result;

    while(!q.empty()){

        int size=q.size();
        vector<int> ans(size);

        for(int i=0;i<size;i++){
            node* topnode = q.front();
            q.pop();
            int index=(flag)?i:size-i-1;
            ans[index]=topnode->data;

            if(topnode->left){
                q.push(topnode->left);
            }
            if(topnode->right){
                q.push(topnode->right);
            }
        }

        flag =!flag;

        for(int i:ans){
            cout<<i;
        } 
    }
}



int main(){
    node* root = NULL;
    root = buildTree(root);
    ZigzagTraversal(root);
    return 0;
}