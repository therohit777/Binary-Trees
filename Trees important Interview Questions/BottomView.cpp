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







void topView(node* root){
    map<int,int> nodestore;
    queue<pair<node*,int>> q;
    vector<int> ans;

    if(root==NULL){
        return;
    }

    q.push(make_pair(root,0));
    while(!q.empty()){
        pair<node*,int> topnode = q.front();
        q.pop();
        node* frontnode = topnode.first;
        int horizontal = topnode.second;

        nodestore[horizontal]=frontnode->data;

        if(frontnode->left){
            q.push(make_pair(frontnode->left,horizontal-1));
        }
        if(frontnode->right){
            q.push(make_pair(frontnode->right,horizontal+1));
        }
    }

    for(auto i: nodestore){
        ans.push_back(i.second);
    }

    for(auto i:ans){
        cout<<i<<",";
    }
}






int main(){
    node* root = NULL;
    root = buildTree(root);
    topView(root);
    return 0;
}