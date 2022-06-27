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


bool identiacalcheck(node* root1,node* root2){
    if((root1==NULL && root2==NULL)){
        return true;
    }
    if((root1!=NULL && root2==NULL) || (root1==NULL && root2!=NULL)){
        return false;
    }

    bool left = identiacalcheck(root1->left,root2->left);
    bool right= identiacalcheck(root1->right,root2->right);
    bool compare = root1->data ==root2->data;

    if(left && right && compare){
        return true;
    }
    else{
        return false;
    }

}

int main(){
    node* root1=NULL;
    node* root2=NULL;
    root1=buildtree(root1);
    root2=buildtree(root2);
    cout<<endl<<"Identical Check: "<<identiacalcheck(root1,root2);
    return 0;
}