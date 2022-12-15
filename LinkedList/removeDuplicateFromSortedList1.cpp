#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode* deleteDuplicates(ListNode* head) {
        if(!head)
            return head;
        ListNode * start = head;
        ListNode* prev = head;
        head = head->next;
        while(head){
            if(prev->val == head->val){
                prev->next = head->next;
            }
            else 
                prev = head;
            head = head->next;
        }
        return start;
    }