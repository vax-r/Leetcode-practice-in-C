/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
    if (!head || !head->next)
        return head;
    if (left == right)
        return head;
    
    struct ListNode *dummy = calloc(1, sizeof(struct ListNode));
    dummy->next = head;

    // find the left - 1 node
    struct ListNode *first = dummy;
    for (int i=0; i<left - 1; i++)
        first = first->next;
    
    struct ListNode *prev = first, *cur = first->next;
    struct ListNode *tail = cur;
    for (int i=left; i<=right; i++) {
        struct ListNode *next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }

    first->next = prev;
    tail->next = cur;
    return dummy->next;
}