ListNode *detectCycle(ListNode *head) {
    ListNode * s,*f;
    s=f=head;
    while(f && f->next){
        s =s->next;
        f=f->next->next;
        if(s == f)
            break;
    }
    if(!f || !f->next)
        return NULL;
    while(head && s){
        if(head == s)
            return head;
        head = head->next;
        s = s->next;
    }
    return NULL;
}