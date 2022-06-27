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



void levelOrderCreate(node* &root){
    queue<node*>q;
    int data;
    cin>>data;
    root=new node(data);
    q.push(root);

    while(!q.empty()){
        node* topnode=q.front();
        q.pop();

        cout<<"Enter left node for "<<topnode->data<<endl;
        int leftdata;
        cin>>leftdata;
        if(leftdata!=-1){
            topnode->left=new node(leftdata);
            q.push(topnode->left);
        }

        cout<<"Enter right node for "<<topnode->data<<endl;
        int rightdata;
        cin>>rightdata;
        if(rightdata!=-1){
            topnode->right=new node(rightdata);
            q.push(topnode->right);
        }
    }

}




void Level_Order_Traversal(node* root){
    queue<node*>q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){

        node *temp=q.front();
        q.pop();

        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }

}




int main(){
    node* root = NULL;
    levelOrderCreate(root);
    cout<<"Level order traversal:"<<endl;
    Level_Order_Traversal(root);
    return 0;
}