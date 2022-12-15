#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode* reverseBetween(ListNode* head, int left, int right) {
    ListNode * temp = head;
    ListNode * prev = NULL;
    int count = 0;
    while(head){
        count++;
        if(count == left)
            break;
        prev = head;
        head = head->next;
    }
    ListNode * start,*end,*next;
    start = end = next = NULL;
    int c = right-left+1;
    while(head && c--){
        next = head->next;
        if(!start){
            start = end = head;
        }else {
            head->next = start;
            start = head;
        }
        head = next;
    }
    if(prev){
        prev->next = start;
        end->next = head;
        return temp;
    }else {
        end->next = head;
        return start;
    }
}