#include<bits/stdc++.h>
#include "linkedlist.h"
using namespace std;
ListNode * mergeKLists(ListNode *arr[], int k){
    ListNode * start = new ListNode(0);
    ListNode * temp = start;
    ListNode *l1,*l2;
    l1 = NULL;
    for(int i = 0;i<k;i++){
        l2 = arr[i];
        while(l1 && l2){
            if(l1->val < l2->val){
                temp->next = l1;
                l1 = l1->next;
            }else {
                temp->next = l2;
                l2 = l2->next;
            }
            temp = temp->next;
        }
        while(l1){
            temp->next = l1;
            l1 = l1->next;
            temp = temp->next;
        }
        while(l2) {
            temp->next = l2;
            l2 = l2->next;
            temp = temp->next;
        }
        l1 = temp = start;
    }
    return start->next;
}


