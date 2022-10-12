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
bool isIsomorphic(Node *root1,Node *root2){
        if(!root1 && !root2)
            return true;
        else if(!root1 || !root2)
            return false;
        else {
            if(root1->data != root2->data)
                return false;
            bool a = isIsomorphic(root1->left,root2->left) and isIsomorphic(root1->right,root2->right);
            bool b = isIsomorphic(root1->left,root2->right) and isIsomorphic(root1->right,root2->left);
            return a or b;
        }
    }