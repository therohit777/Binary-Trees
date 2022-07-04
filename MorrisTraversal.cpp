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

void MorrisTraversal(node* root){
    node* current;
    node* predecessor;
    if(root==NULL){
        return;
    }

    current=root;

    while(current!=NULL){
        // Check if left == NULL
        if(current->left==NULL){
            cout<<current->data<<" ";
            current=current->right;
        }
        else{
            predecessor=current->left;
            while(predecessor->right!=NULL && predecessor->right!=current){
                 predecessor=predecessor->right;
            }

            if(predecessor->right==NULL){
                predecessor->right=current;
                current=current->left;
            }
            else{
                predecessor->right=NULL;
                cout<<current->data<<" ";
                current= current->right;
            }
        }
    }
}




int main(){
    node* root = NULL;
    root = buildTree(root);
    MorrisTraversal(root);
    return 0;
}