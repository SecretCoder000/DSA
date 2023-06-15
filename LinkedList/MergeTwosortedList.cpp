ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode * start,*end;
    start=end = NULL;
    if(!list1)
        return list2;
    if(!list2)
        return list1;
    if(list1->val <= list2->val){
        start=end=list1;
        list1=list1->next;
    }else {
        start=end=list2;
        list2=list2->next;
    }
    //1 2 4
    //1 2 4
    end->next = NULL;
    while(list1 && list2){
        if(list1->val <= list2->val){
            end->next = list1;
            list1=list1->next;
        }
        else {
            end->next = list2;
            list2=list2->next;
        }
        end = end->next;
        end->next = NULL;
    }
    if(list1){
        end->next = list1;
    }
    if(list2){
        end->next = list2;
    }
    return start;
}