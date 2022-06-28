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






Approach1
// void leftView(node* root){
//     map<int,int> nodestore;
//     queue<pair<node*,int>> q;
//     vector<int> ans;

//     if(root==NULL){
//         return;
//     }

//     q.push(make_pair(root,0));
//     while(!q.empty()){
//         pair<node*, int> topnode = q.front();
//         q.pop();

//         node* frontnode = topnode.first;
//         int level = topnode.second;

//         if(nodestore.find(level) == nodestore.end()){
//             nodestore[level]=frontnode->data;
//         }

//         if(frontnode->left){
//             q.push(make_pair(frontnode->left,level+1));
//         }
//         if(frontnode->right){
//             q.push(make_pair(frontnode->right,level+1));
//         }
//     }

//     for(auto i: nodestore){
//         ans.push_back(i.second);
//     }

//     for(auto i:ans){
//         cout<<i<<",";
//     }
// }


// Approach2
void leftView(node* root,int level,map<int,int> &nodestore){
    if(root==NULL){
        return ;
    }

    if(nodestore.find(level)==nodestore.end()){
        nodestore[level]=root->data;
        cout<<root->data<<",";
    }
    leftView(root->left,level+1,nodestore);
    leftView(root->right,level+1,nodestore);

}





int main(){
    node* root = NULL;
    root = buildTree(root);
    leftView(root);
    return 0;
}