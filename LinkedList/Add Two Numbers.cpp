ListNode * reverse(ListNode * head){
    ListNode * start = head;
    ListNode * end = head;
    head = head->next;
    end->next = NULL;
    while(head){
        end->next = head;
        head = head->next;
        end = end->next;
    }
    return start;
}
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    l1 = reverse(l1);
    l2 = reverse(l2);
    ListNode * start,*end;
    start=end=NULL;
    int carry = 0;
    while(l1 && l2){
        int temp = l1->val+l2->val+carry;
        ListNode * newNode = new ListNode(temp%10);
        l1 = l1->next;
        l2 = l2->next;
        carry = temp/10;
        if(!start){
            start = end = newNode;
        }else {
            end->next = newNode;
            end = end->next;
        }
    }
    while(l1){
        int temp = l1->val+carry;
        ListNode * newNode = new ListNode(temp%10);
        l1 = l1->next;
        carry = temp/10;
        if(!start){
            start = end = newNode;
        }else {
            end->next = newNode;
            end = end->next;
        }
    }
    while(l2){
        int temp = l2->val+carry;
        ListNode * newNode = new ListNode(temp%10);
        l2 = l2->next;
        carry = temp/10;
        if(!start){
            start = end = newNode;
        }else {
            end->next = newNode;
            end = end->next;
        }
    }
    if(carry!=0){
        ListNode * newNode = new ListNode(carry);
        end->next = newNode;
    }
    return start;
}