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


void Postorder(node* root){

    if(root==NULL){
        return;
    }

    Postorder(root->left);
    Postorder(root->right);
    cout<<root->data<<" ";
}    


void mapinitialise(map<int,int> &nodeorder,int in[],int n){
    for(int i=0;i<n;i++){
        nodeorder[in[i]]=i;
    }
}

node* buildTreeusingInorderandPreorder(int pre[],int n,int &index,int in[],int startpos,int endpos,map<int,int> nodeorder){
    if( index>=n || startpos>endpos){
        return NULL;
    }


    int element = pre[index++];
    node* root = new node(element);
    int position = nodeorder[element];

    root->left = buildTreeusingInorderandPreorder(pre,n,index,in,startpos,position-1,nodeorder);
    root->right = buildTreeusingInorderandPreorder(pre,n,index,in,position+1,endpos,nodeorder);

    return root;
}

int main(){
    node* root = NULL;
    int n=6;
    int in[] = {3,1,4,0,5,2};
    int pre[] = {0,1,3,4,2,5};
    map<int,int> nodeorder;
    mapinitialise(nodeorder,in,n);
    int index=0;
    root = buildTreeusingInorderandPreorder(pre,n,index,in,0,n-1,nodeorder);
    
    Postorder(root);
    return 0;
}