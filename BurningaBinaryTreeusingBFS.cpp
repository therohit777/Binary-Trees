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

node* MappingofNodetoParent(node* root,map<node*,node*> &nodetoparent ,int target){
        queue<node*> q;
        q.push(root);

        nodetoparent[root] = NULL;
        node* targetnode=NULL;

        while(!q.empty()){
            node* frontnode = q.front();
            q.pop();

            if(target==frontnode->data){
                targetnode=frontnode;
            }
            if(frontnode->left){
                nodetoparent[frontnode->left]=frontnode;
                q.push(frontnode->left);
            }
            if(frontnode->right){
                nodetoparent[frontnode->right]=frontnode;
                q.push(frontnode->right);
            }
        }

        return targetnode;
}








int BurnTree(node* root,map<node*,node*> nodeparent){
   
    queue<node*> q;
    map<node*,bool> visit;
      
    
    q.push(root);
    visit[root]=true;

    int time=0;

    while(!q.empty()){
        int flag=0;
        int size=q.size();

        for(int i=0;i<size;i++){
            node* frontnode = q.front();
            q.pop();            
            
            if(frontnode->left && !visit[frontnode->left]){
                flag=1;
                visit[frontnode->left]=true;
                q.push(frontnode->left);
            }

            if(frontnode->right && !visit[frontnode->right]){
                flag=1;
                visit[frontnode->right]=true;
                q.push(frontnode->right);
            }

            if(nodeparent[frontnode] && !visit[nodeparent[frontnode]]){
                flag=1;
                visit[nodeparent[frontnode]]=true;
                q.push(nodeparent[frontnode]);
            }
        }

        if(flag==1){
            time++;
        }
    }
    return time;
}


int main(){
    node* root = NULL;
    int target = 8;
    root = buildTree(root);
    map<node*,node*> nodetoparent;
    
    node* targetnode = MappingofNodetoParent(root,nodetoparent,target);
    int n=8;
    int TimetoBurn = BurnTree(targetnode,nodetoparent);
    cout<<"Time take to burn a tree from a given node: "<<TimetoBurn<<endl;
    return 0;
}