#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode* pairWiseSwap(ListNode* head) {
    if(!head || !head->next)
        return head;
    ListNode * start = NULL;
    ListNode * prev = NULL;
    while(head && head->next){
        ListNode * temp = head->next;
        if(!start){
            start = temp;
            head->next = temp->next;
            start->next = head;
        }else {
            prev->next = temp;
            head->next = temp->next;
            temp->next = head;
        }
        prev = head;
        head = head->next;
    }
    return start;
}

