#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode* deleteMiddle(ListNode* head) {
    if(!head || !head->next)        
        return NULL;
    ListNode * slow ,*fast,*prev,*start;
    start = head;
    slow = fast = head;
    prev = NULL;
    while (fast && fast->next){
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    if(prev)
        prev->next = slow->next; 
    return start;
}