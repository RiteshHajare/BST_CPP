//O(h)

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

bool findKey(Node* root,int val){
    if(root==nullptr)return false;
    if(root->data==val)return true;
    else if(val<root->data){
        return findKey(root->left,val);
    }else{
        return findKey(root->right,val);
    }
}

int main()
{
    int nodes[] = {5,1,3,4,2,7};
    Node* root = nullptr;
    for(int i=0;i<6;i++){
         root = insert(root,nodes[i]);
    }
    cout<<findKey(root,6);
    return 0;
}
