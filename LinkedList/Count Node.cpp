int NodeCount(ListNode * start){
    int count = 0;
    while (start){
        count++;
        start = start->next;
    }
    return count;
}