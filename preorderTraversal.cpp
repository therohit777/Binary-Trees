#include<iostream>
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

void Preorder(node* root){

    if(root==NULL){
        return;
    }

    cout<<root->data<<" ";
    Preorder(root->left);
    Preorder(root->right);

}    


int main(){
    node* root = NULL;
    root = buildTree(root);
    Preorder(root);
    return 0;
}