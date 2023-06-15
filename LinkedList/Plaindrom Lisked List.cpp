int NodeCount(ListNode * start){
    int count = 0;
    while (start){
        count++;
        start = start->next;
    }
    return count;
}
ListNode * reverse(ListNode * head){
    ListNode * start = head;
    head = head->next;
    start->next = NULL;
    while(head){
        ListNode * temp = head->next;
        head->next = start;
        start = head;
        head = temp;
    }
    return start;
}
bool isPalindrome(ListNode* head) {
    if(!head || !head->next)
        return true;
    int n = NodeCount(head);
    int temp = n/2;
    ListNode * start = head;
    ListNode * end = NULL;
    while(temp--){
        end = head;
        head=head->next;
    }
    if(n&1)
        head=head->next;
    end->next = NULL;
    start = reverse(start);
    while(head){
        if(start->val != head->val)
            return false;
        start = start->next;
        head = head->next;
    }
    return true;
}