bool hasCycle(ListNode *head) {
    if(!head || !head->next)
        return false;
    ListNode * s,*f;
    s=f=head;
    do {
        s = s->next;
        f = f->next->next;
    } while (s && f && f->next && s != f);
    return s==f;
}