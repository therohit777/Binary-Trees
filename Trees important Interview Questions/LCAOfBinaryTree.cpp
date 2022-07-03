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

node* LCAofBinaryTree(node* root,int n1,int n2,int & flag){
    if(root==NULL){
        return NULL;
    }
    if(root->data==n1 || root->data== n2){
        return root;
    }

    node* leftnode = LCAofBinaryTree(root->left,n1,n2,flag);
    node* rightnode = LCAofBinaryTree(root->right,n1,n2,flag);

    if((leftnode != NULL || rightnode != NULL) && flag==0){
        flag=1;
        return root;
    }
    else if(leftnode != NULL || rightnode == NULL){
        return leftnode;
    }
    else if(leftnode == NULL || rightnode != NULL){
        return rightnode;
    }
    else{
        return NULL;
    }

}

int main(){
    node* root = NULL;
    int n1=3;
    int n2=4;
    root = buildTree(root);
    int flag=0;
    node* ans = LCAofBinaryTree(root,n1,n2,flag);
    cout<<"LCA of two given nodes in a BinaryTree: "<<ans->data;
    return 0;
}