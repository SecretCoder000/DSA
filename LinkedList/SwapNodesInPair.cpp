#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode* swapPairs(ListNode* head) {
    ListNode * start = head;
    ListNode * f = head;
    ListNode * s = head->next;
    while(head->next){
        f = head;
        s = head->next;
        swap(f->val,s->val);
        head = s->next;
    }
    return start;
}
//ListNode * createNode(vector<int> arr){
//
//    ListNode * start = NULL;
//    ListNode * end = NULL;
//    for(int i =0;i<arr.size();i++){
//        ListNode * temp = new ListNode(arr[i]);
//        if(start == NULL)
//            end = start = temp;
//        else {
//            end->next = temp;
//            end = end->next;
//        }
//    }
//    return start;
//}
//int main(){
//    int n;
//    cin>>n;
//    vector<int> arr(n,0);
//    for(int i =0;i<n;i++)
//        cin>>arr[i];
//    ListNode * start = createNode(arr);
//    swapPairs(start);
//    return 0;
//}

