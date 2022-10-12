
#include<bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    struct Node *left,*right;
    Node(int x){
        data = x;
        left=right=NULL;
    }
};
Node * findPred(Node * root){
    if(root == NULL)
        return NULL;
    root = root->left;
    Node * prev = NULL;
    while(root){
        prev = root;
        root = root->right;
    }
    return prev;
}
Node * findSucc(Node * root){
    if(root == NULL)
        return NULL;
    root = root->right;
    Node * prev = NULL;
    while(root){
        prev = root;
        root = root->left;
    }
    return prev;
}
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key){
    suc = NULL;
    pre = NULL;
    Node * target = NULL;
    while (root){
        if(key < root->data){
            suc = root;
            root = root->left;
        }else if(key > root->data){
            pre = root;
            root = root->right;
        }else {
            target = root;
            break;
        }
    }
    if(target && root->left)
        pre = findPred(target);
    if(target && root->right)
        suc = findSucc(target);
    
}