/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head){
    if (!head || !head->next)
        return head;
    struct ListNode *cnode;
    cnode = head;
    while (cnode->next) {
        if (cnode->val == cnode->next->val)
            cnode->next = cnode->next->next;
        else
            cnode = cnode->next;
    }
    return head;
}