struct Node {
    int data;
    struct Node *left,*right;
    Node(int x){
        data = x;
        left=right=NULL;
    }
};

class cmp
{   public:
    bool operator()(Node* a,Node* b)
    {
        return a->data >b->data;
    }
};
class Solution
{

    void preOrder(Node * root,string str,vector<string> & ans){
        if(root){
            if(!root->left && !root->right){
                ans.push_back(str);
                return;
            }
            preOrder(root->left,str+'0',ans);
            preOrder(root->right,str+'1',ans);
        }
    }
public:
    vector<string> huffmanCodes(string S,vector<int> f,int n){
        priority_queue<Node*,vector<Node*>,cmp> que;
        for(int i =0;i<n;i++){
            auto node = new Node(f[i]);
            que.push(node);
        }
        while(que.size() > 1){
            Node * left = que.top();
            que.pop();
            Node * right = que.top();
            que.pop();
            Node *parent = new Node(left->data+right->data);
            parent->left = left;
            parent->right = right;
            que.push(parent);
        }
        Node * root = que.top();
        que.pop();
        vector<string> ans;
        preOrder(root,"",ans);
        return ans;
    }