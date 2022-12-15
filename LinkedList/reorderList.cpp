#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void reorderList(ListNode* head) {
    vector<ListNode*> temp;
    while (head){
        temp.push_back(head);
    }        
    int i =0;
    int h = temp.size()-1;
    while(i<h){
        temp[i]->next = temp[h];
        temp[h]->next = temp[i+1];
        i++;
        h--;
    }
    temp[i]->next = NULL;
}