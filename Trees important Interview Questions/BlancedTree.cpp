#include<iostream>
using namespace std ;

class node{
    public:
     int data;
     node* left;
     node* right;
     node(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;
     }
};

node* buildtree(node* root){
    int data;
    cout<<"Enter data";
    cin>>data;
    root=new node(data);

    if(data==-1){
        return NULL; 
    }

    cout<< "Left of node "<<root->data<<endl;
    root->left=buildtree(root->left);
    cout<< "Right of node "<<root->data<<endl;
    root->right=buildtree(root->right);
    return root;

}

int height(node* root){
    if(root==NULL){
        return 0;
    }

    int leftcount = height(root->left);
    int rightcount = height(root->right);
    
    return max(leftcount,rightcount)+1;

}

bool isBalanced(node* root){
    if(root==NULL){
        return true;
    }

    bool left=isBalanced(root->left);
    bool right=isBalanced(root->right);
    bool diff=abs(height(root->left)-height(root->right))<=1;

    if(left && right && diff){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    node* root=NULL;
    root=buildtree(root);
    cout<<endl<<"Balanced : "<<isBalanced(root);
    return 0;
}