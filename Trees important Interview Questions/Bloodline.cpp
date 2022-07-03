#include<iostream>
#include<bits/stdc++.h>
#include<climits>
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


void BloodLine(node* root, int len,int sum,int &maxlen,int &maxsum){
    if(root==NULL){
        if(len>maxlen){
            maxlen=len;
            maxsum=sum;
        }
        else if(len==maxlen){
            maxsum=max(sum,maxsum);
        }
        return;
    }
    sum=sum+root->data;
    BloodLine(root->left,len+1,sum,maxlen,maxsum);
    BloodLine(root->right,len+1,sum,maxlen,maxsum);
}






int main(){
    node* root = NULL;
    root = buildTree(root);
    int sum = 0;
    int len = 0;
    int maxlen = 0;
    int maxsum = INT_MIN;  
    BloodLine(root,len,sum,maxlen,maxsum );

    cout<<"Bloodline: "<<maxsum<<endl;
    return 0;
}