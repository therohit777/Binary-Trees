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

pair<int,bool> isSumTree(node* root){
    // NULL Base contion
    if(root==NULL){
        pair<int,bool> ans = make_pair(0,true);
        return ans;
    }

    // Leaf Base condition
    if(root->left==NULL && root->right==NULL){
        pair<int,bool> ans=make_pair(root->data,true);
        return ans;
    }

    // left and right recursive calls
    pair<int,bool> leftnode = isSumTree(root->left);
    pair<int,bool> rightnode = isSumTree(root->right); 


    // current check = value of left tree + righttree == currentnode or not.    
    // Check left,right and currentchecknode is true or not
    bool left =  leftnode.second;  
    bool right = rightnode.second;
    bool checkcurrent = leftnode.first+rightnode.first == root->data;

    pair<int,bool> ans;
    if(left && right && checkcurrent){
        ans.second=true;
        ans.first=leftnode.first+rightnode.first+root->data;
    }
    else{
       ans.second=false;
    }
    return ans;
}

int main(){
    node* root=NULL;
    root=buildtree(root);
    pair<int,bool> sumtree = isSumTree(root);
    cout<<endl<<"SumTree : "<< sumtree.second;
    return 0;
}