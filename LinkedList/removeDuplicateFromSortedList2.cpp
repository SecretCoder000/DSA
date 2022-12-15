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
        stack<ListNode*> st;
        ListNode * prev = head;
        st.push(head);
        head = head->next;
        while(head){
            if(!st.empty() && head && head->val == st.top()->val){
                while(!st.empty() && head && head->val == st.top()->val){
                      head = head->next;
                }
                st.pop();
            }
            else {
                st.push(head);
                head = head->next;
            }
        }
        ListNode* start,*end ;
        start = end = NULL;
        while(!st.empty()){
            if(start == NULL){
                start = end = st.top();
            }else {
                st.top()->next = start;
                start = st.top();
            }
            st.pop();
        }
        if(end)
            end->next = NULL;
        return start;
    }