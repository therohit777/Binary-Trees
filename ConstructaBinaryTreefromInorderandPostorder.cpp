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


void Preorder(node* root){

    if(root==NULL){
        return;
    }

    cout<<root->data<<" ";
    Preorder(root->left);
    Preorder(root->right);

}     


void mapinitialise(map<int,int> &nodeorder,int in[],int n){
    for(int i=0;i<n;i++){
        nodeorder[in[i]]=i;
    }
}

node* buildTreeusingInorderandPreorder(int post[],int n,int &index,int in[],int startpos,int endpos,map<int,int> nodeorder){
    if( index<0 || startpos>endpos){
        return NULL;
    }


    int element = post[index--];
    node* root = new node(element);
    int position = nodeorder[element];

    root->right = buildTreeusingInorderandPreorder(post,n,index,in,position+1,endpos,nodeorder);
    root->left = buildTreeusingInorderandPreorder(post,n,index,in,startpos,position-1,nodeorder);
 

    return root;
}

int main(){
    node* root = NULL;
    int n=8;
    int in[] = {4,8,2,5,1,6,3,7};
    int post[] = {8,4,5,2,6,7,3,1};
    map<int,int> nodeorder;
    mapinitialise(nodeorder,in,n);
    int index=7;
    root = buildTreeusingInorderandPreorder(post,n,index,in,0,n-1,nodeorder);
    
    Preorder(root);
    return 0;
}