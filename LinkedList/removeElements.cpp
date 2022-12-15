#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode* removeElements(ListNode* head, int val) {
        ListNode * prev = NULL;
        ListNode * start = head;
        while(head){
            if(head->val == val){
                if(prev == NULL){
                    start=start->next;
                }else{
                    prev->next = head->next;
                }
            }
            else 
                prev = head;
            head = head->next;
        }
        return start;
    }