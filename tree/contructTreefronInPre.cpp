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

Node * solve(vector<int> in,vector<int> pre){
    if(in.empty())
        return NULL;
    else {
        Node * root = new Node(pre[0]);
        vector<int> leftIn,leftPre;
        vector<int> rightIn,rightPre;
        int  i =0;
        for(i;i<in.size();i++){
            if(in[i] != pre[0])
                leftIn.push_back(in[i]);
            else 
                break;
        }
        i++;
        for(i;i<in.size();i++)
            rightIn.push_back(in[i]);
        i=1;
        for(i;i<=leftIn.size();i++){
            leftPre.push_back(pre[i]);
        }
        
        for(i;i<pre.size();i++){
            rightPre.push_back(pre[i]);
        }
        
        Node * l = solve(leftIn,leftPre);
        Node * r = solve(rightIn,rightPre);
        root->left = l;
        root->right = r;
        return root;
    }
}