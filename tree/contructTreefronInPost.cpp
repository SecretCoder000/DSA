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

Node * solve(vector<int> in,vector<int> post){
    if(in.empty())
        return NULL;
    else {
        Node * root = new Node(post[post.size()-1]);
        vector<int> leftIn,leftpost;
        vector<int> rightIn,rightpost;
        int  i =0;
        for(i;i<in.size();i++){
            if(in[i] != post[post.size()-1])
                leftIn.push_back(in[i]);
            else 
                break;
        }
        i++;
        for(i;i<in.size();i++)
            rightIn.push_back(in[i]);
        i=0;
        for(i;i<=leftIn.size();i++){
            leftpost.push_back(post[i]);
        }
        
        for(i;i<post.size()-1;i++){
            rightpost.push_back(post[i]);
        }
        
        Node * l = solve(leftIn,leftpost);
        Node * r = solve(rightIn,rightpost);
        root->left = l;
        root->right = r;
        return root;
    }
}