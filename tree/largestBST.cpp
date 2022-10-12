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
class NodeValue {
    public:
        int min,max,size;
    NodeValue(int min,int max,int size){
        this->min = min;
        this->max = max;
        this->size = size;
    }
};
NodeValue solve(Node * root){
    if (root == NULL)
        return NodeValue(INT_MAX,INT_MIN,0);
    else {
        NodeValue l = solve(root->left);
        NodeValue r = solve(root->right);
        if(root->data > l.max && root->data < r.min)
            return NodeValue(min(root->data,l.min),max(root->data,r.max),l.size+r.size+1);
        
        return NodeValue(INT_MAX,INT_MIN,max(l.size,r.size));
    }
}