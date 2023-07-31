

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

Node* isSeccessor(Node* root){
    while(root->left!=nullptr){
        root=root->left;
    }
    return root; 
}

Node* deleteNode(Node* root,int val){
    if(val<root->data){
        root->left = deleteNode(root->left,val);
    }
    else if(val>root->data){
        root->right = deleteNode(root->right,val);
    }else{
        //case1 -leafnode
        if(root->right==nullptr && root->left==nullptr){
            return nullptr;
        }
        //case 2 -with one child
        if(root->left==nullptr) return root->right;
        if(root->right==nullptr) return root->left;
        
        //case3 -having both child
        Node* successor = isSeccessor(root->right);
        root->data = successor->data;
        root->right = deleteNode(root->right,successor->data);
    }
    return root;
    
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
    preOrder(root);cout<<endl;
    deleteNode(root,4);
    preOrder(root);
    return 0;
}
