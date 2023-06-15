ListNode * reverse(ListNode * head){
    ListNode * start = head;
    ListNode * end = head;
    head = head->next;
    end->next = NULL;
    while(head){
        end->next = head;
        head = head->enxt;
        end = end->next;
    }
    return start;
}

