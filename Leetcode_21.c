/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    if ( !list1 )
        return list2;
    if ( !list2 )
        return list1;
    struct ListNode *cur_1, *cur_2, *merge_head, *merge_tail;
    cur_1 = list1;
    cur_2 = list2;
    if ( cur_1->val <= cur_2->val ) {
        merge_head = cur_1;
        merge_tail = cur_1;
        cur_1 = cur_1->next;
    }
    else {
        merge_head = cur_2;
        merge_tail = cur_2;
        cur_2 = cur_2->next;
    }
    while ( cur_1 && cur_2 ) {
        if ( cur_1->val <= cur_2->val ) {
            merge_tail->next = cur_1;
            merge_tail = cur_1;
            cur_1 = cur_1->next;
        }
        else {
            merge_tail->next = cur_2;
            merge_tail = cur_2;
            cur_2 = cur_2->next;
        }
    }
    if ( cur_1 )
        merge_tail->next = cur_1;
    if ( cur_2 )
        merge_tail->next = cur_2;
    return merge_head;
}