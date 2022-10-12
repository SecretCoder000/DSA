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

bool isBST(Node * root,Node * &prev){
    if(root == NULL)
        return true;
    else {
        if(!isBST(root->left,prev))
            return false;
        if(prev && prev->data >= root->data)
            return false;
        prev = root;
        return isBST(root->right,prev);
    }
}