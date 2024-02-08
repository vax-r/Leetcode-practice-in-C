/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* mergeNodes(struct ListNode* head) {
    struct ListNode dummy;
    head = head->next;

    for (struct ListNode *prev = &dummy; head; head = head->next) {
        int sum = 0;
        while (head->val) {
            sum += head->val;
            head = head->next;
        }

        prev->next = head;
        head->val = sum;
        prev = head;
    }

    return dummy.next;
}