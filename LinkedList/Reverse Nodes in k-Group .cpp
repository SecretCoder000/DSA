pair<ListNode*,ListNode*> reverseStartToEnd(ListNode * start){
    ListNode *s=NULL,*e=NULL;
    while (start){
        ListNode * temp = start->next;
        if(!s){
            e=s=start;
            e->next=NULL;
        }
        else {
            start->next=s;
            s = start;
        }
        start = temp;
    }
    return {s,e};
}
ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode *start,*end;
    start=end=NULL;
    int c = k;
    ListNode *cStart,*cEnd;
    cStart =cEnd = NULL;
    while (head){
        ListNode * temp = head->next;
        c--;
        if(!cStart){
            cStart = cEnd = head;
        }else {
            cEnd = head;
        }
        if(c == 0){
            cEnd->next = NULL;
            auto res = reverseStartToEnd(cStart);
            if(!start){
                start = res.first;
                end = res.second;
            }else {
                end->next = res.first;
                end = res.second;
            }
            cStart = cEnd = NULL;
            c = k;
        }else if(!temp){
            end->next = cStart;
        }
        head = temp;
    }
    return start;
}