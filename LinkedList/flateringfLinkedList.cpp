#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode *bottom;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode *flatten(ListNode *root){
    ListNode * start = new ListNode(0);
    ListNode * temp = start;
    ListNode * l1 , *l2;
    l1 = NULL ;
    l2 = root;
    while(root){
        while(l1 && l2){
            if(l1->val < l2->val){
                temp->bottom = l1;
                l1 = l1->bottom;
            }else {
                temp->bottom = l2;
                l2 = l2->bottom;
            }
            temp = temp->bottom;
        }
        while(l1){
            temp->bottom = l1;
            l1 = l1->bottom;
            temp = temp->bottom;
        }
        while(l2) {
            temp->bottom = l2;
            l2 = l2->bottom;
            temp = temp->bottom;
        }
        l1 = start->bottom;
        l2 = root->next;
        temp = start;
        root = root->next;
    }
    return start->bottom;
}
