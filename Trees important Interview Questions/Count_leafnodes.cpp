#include<iostream>
using namespace std;

class node{
    public:
       int data;
       node* left;
       node* right;

       node(int d){
        this -> data=d;
        this->left=NULL;
        this->right=NULL;
       }
};


void countleafnode(node*root,int &count){
    if(root==NULL){
        return;
    }
    countleafnode(root->left,count);
    countleafnode(root->right,count);
    if(root->left ==NULL && root->right==NULL){
        count++;
    }
}


node* buildtree(node* root){
    int data;
    cout<<"Enter data: ";
    cin>>data;
    root=new node(data);

    if(data==-1){
        return NULL;
    }

    cout<<"Enter left node for "<<root->data<<endl;
    root->left= buildtree(root->left);
    cout<<"Enter right node for "<<root->data<<endl;
    root->right= buildtree(root->right);
    return root;

}

int main(){
    node* root=NULL;
    root=buildtree(root);
    int count=0;
    countleafnode(root,count);
    cout<<"Number of leaf nodes: "<<count;
    return 0;
}