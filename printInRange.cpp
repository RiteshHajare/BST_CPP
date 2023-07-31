

#include <iostream>

using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    
    Node(int val){
        data=val;
        left=nullptr;
        right=nullptr;
    }
};

Node* insert(Node* root,int val){
    if(root==nullptr){
        root = new Node(val);
        return root;
    }
    
    if(root->data>val){
        root->left = insert(root->left,val);
    }else{
        root->right = insert(root->right,val);
    }
    return root;
}


void printNodes(Node* root,int x,int y){
    if(root==nullptr)return;
    if(root->data>=x && root->data<=y){
        printNodes(root->left,x,y);
        cout<<root->data<<" ";
        printNodes(root->right,x,y);
    }else if(x>root->data){
        printNodes(root->right,x,y);
    }else if(y<root->data){
        printNodes(root->left,x,y);
    }
    
}



void preOrder(Node* root){
    if(root==nullptr)return;
    
    preOrder(root->left);
    cout<<root->data<<" ";
    preOrder(root->right);
}

int main()
{
    int nodes[] = {8,5,3,1,4,6,10,11,14};
    Node* root = nullptr;
    for(int i=0;i<9;i++){
         root = insert(root,nodes[i]);
    }
    
    printNodes(root,3,12);
   
    return 0;
}
