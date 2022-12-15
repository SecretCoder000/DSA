#include<bits/stdc++.h>
#include "LinkedList/linkedlist.h"
using namespace std;
TreeNode* sortedListToBST(ListNode* head) {
    if(!head)
        return NULL;
    ListNode * s ,*f,*prev,*start;
    start = head;
    prev = NULL;
    s=f=head;
    while(f && f->next){
        prev = s;
        s = s->next;
        f = f->next->next;
    }
    if(!prev){
        TreeNode * temp =  new TreeNode(s->val);
        return temp;
    }
    prev->next = NULL;
    TreeNode * left = sortedListToBST(start);
    TreeNode * right = sortedListToBST(s->next);
    TreeNode * temp = new TreeNode(s->val);
    temp->left = left;
    temp->right = right;
    return temp;
}
