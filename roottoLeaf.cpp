
#include<vector>
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

void preOrder(Node* root){
    if(root==nullptr)return;
    
    preOrder(root->left);
    cout<<root->data<<" ";
    preOrder(root->right);
}


void printRoot2Leaf(Node* root,vector<int>& path){
    if(root==nullptr){
        
        return;
    }
    path.push_back(root->data);
    if(root->left==nullptr && root->right==nullptr){
        for(auto i:path){
            cout<<i<<" ";
        }cout<<endl;
    }
    else{printRoot2Leaf(root->left,path);
    printRoot2Leaf(root->right,path);}
    path.pop_back();
}



int main()
{
    int nodes[] = {8,5,3,1,4,6,10,11,14};
    Node* root = nullptr;
    for(int i=0;i<9;i++){
         root = insert(root,nodes[i]);
    }
    vector<int> path;
    printRoot2Leaf(root,path);
   
    return 0;
}
