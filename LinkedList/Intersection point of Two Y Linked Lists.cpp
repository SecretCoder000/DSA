int NodeCount(ListNode * start){
    int count = 0;
    while (start){
        count++;
        start = start->next;
    }
    return count;
}
ListNode *getIntersectionNode(ListNode *l1, ListNode *l2) {
    int n1 = NodeCount(l1);
    int n2 = NodeCount(l2);
    while(n1 > n2 && l1){
        l1 = l1->next;
        n1--;
    }
    while(n2 > n1 && l2){
        l2 = l2->next;
        n2--;
    }
    while(l1 && l2 && l1 != l2){
        l1 = l1->next;
        l2 = l2->next;
    }
    return l1;
}