#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
int count(ListNode * head){
    int count = 0;
    while (head){
        count++;
        head = head->next;
    }
    return count;
}
ListNode* rotateRight(ListNode* head, int k) {
    int n = count(head);
    k %= n;
    int c = n-k;
    ListNode * start = head;
    ListNode * prev = NULL;
    while (c--){
        prev = head;
        head = head->next;
    }
    if(!prev)
        return start;
    prev->next = NULL;
    ListNode* temp1 = head;
    ListNode* temp2 = head;
    while (head->next){
        temp2 = head;
        head = head->next;
    }
    temp2->next = start;
    return temp1;
}