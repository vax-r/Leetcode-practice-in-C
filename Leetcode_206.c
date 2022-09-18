struct ListNode* reverseList(struct ListNode* head){
    struct ListNode *cur,*right,*left;
    left=NULL;
    cur=head;
    while(cur!=NULL){
        right=cur->next;
        cur->next=left;
        left=cur;
        cur=right;
    }
    return left;
}