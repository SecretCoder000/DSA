#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *moveToFront(ListNode *head){
    ListNode * start = head;
    ListNode * prev = NULL;
    while(head->next){
        prev = head;
        head = head->next;
    }
    if(prev){
        prev->next = NULL;
        head->next = start;
    }
    return head;
}