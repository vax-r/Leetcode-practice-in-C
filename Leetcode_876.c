struct ListNode* middleNode(struct ListNode* head){
    //count the list length
    struct ListNode* cur=head;
    int i,len=0;
    while(cur!=NULL){
        len+=1;
        cur=cur->next;
    }
    cur=head;
    for(i=0;i<(len/2);i++)
        cur=cur->next;
    return cur;
}