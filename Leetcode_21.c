/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){

    if (!list1)
        return list2;
    if (!list2)
        return list1;

    struct ListNode *head = NULL;
    struct ListNode **tail = &head;
    while (list1 && list2) {
        if (list1->val <= list2->val) {
            *tail = list1;
            tail = &(list1->next);
            list1 = list1->next;
        } else {
            *tail = list2;
            tail = &(list2->next);
            list2 = list2->next;
        }
    }
    *tail = (struct ListNode *) ((uintptr_t) list1 | (uintptr_t) list2);
    return head;
}