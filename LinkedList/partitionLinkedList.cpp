#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode * createNode(vector<int> arr){

    ListNode * start = NULL;
    ListNode * end = NULL;
    for(int i =0;i<arr.size();i++){
        ListNode * temp = new ListNode(arr[i]);
        if(start == NULL)
            end = start = temp;
        else {
            end->next = temp;
            end = end->next;
        }
    }
    return start;
}
ListNode* partition(ListNode* head, int x) {
    ListNode * lStart,*lEnd;
    ListNode * rStart,*rEnd;
    ListNode* mid;
    mid = lStart = rStart = NULL;
    while(head){
        ListNode * temp = head->next;
        if(head->val < x){
            if(!lStart){
                lStart = lEnd = head;
            }else {
                lEnd->next = head;
                lEnd = lEnd->next;
            }
            lEnd->next = NULL;
        }
        else {
            if(!rStart){
                rStart = rEnd = head;
            }else {
                rEnd->next = head;
                rEnd = rEnd->next;
            }
            rEnd->next = NULL;
        }
        head = temp;
    }
    if(lEnd)
        lEnd->next = rStart;
    return lStart?lStart:rStart;
}

