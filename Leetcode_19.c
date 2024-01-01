/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

int indexFromHead(struct ListNode *head, int n) {
    int len = 0;
    for (struct ListNode *cur = head; cur; cur = cur->next)
        len++;
    return len - n;
}

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    if (!head)
        return head;
    int real_n = indexFromHead(head, n);
    struct ListNode *pre, *cur;
    pre = NULL;
    cur = head;
    for (int i=0; i<real_n; i++) {
        pre = cur;
        cur = cur->next;
    }
    if (pre) {
        pre->next = cur->next;
    } else {
        head = head->next;
    }
    free(cur);
    return head;
}