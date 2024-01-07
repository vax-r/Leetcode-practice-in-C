/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode *removeNode(struct ListNode *head, struct ListNode *dnode) {
    if (head == dnode) {
        head = head->next;
        return head;
    }
    struct ListNode *cur = head;
    while (cur->next != dnode)
        cur = cur->next;
    cur->next = dnode->next;

    return head;
}

struct ListNode* removeElements(struct ListNode* head, int val) {
    for (struct ListNode *cur = head; cur; cur = cur->next)
        if (cur->val == val)
            head = removeNode(head, cur);
    return head;
}