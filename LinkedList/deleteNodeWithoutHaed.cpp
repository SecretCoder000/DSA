#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void deleteNode(ListNode* node) {
        ListNode* prev = NULL;
        while(node->next){
            node->val = node->next->val;
            prev = node;
            node = node->next;
        }
        prev->next = NULL;
    }