/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int countLen(struct ListNode *head) {
    int len = 0;
    for (struct ListNode *cur=head; cur; cur = cur->next)
        len++;
    return len;
}


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){

    if (!l1)
        return l2;
    if (!l2)
        return l1;
    
    int len1 = countLen(l1);
    int len2 = countLen(l2);

    struct ListNode *cur1, *cur2;
    if (len1 >= len2) {
        cur1 = l1;
        cur2 = l2;
    } else {
        cur1 = l2;
        cur2 = l1;
    }

    int carry = 0;
    while (cur1 && cur2) {
        int tmp = cur1->val + cur2->val;
        cur1->val = (carry + tmp) % 10;
        carry = (carry + tmp) / 10;
        if (carry && !cur1->next) {
            cur1->next = calloc(1, sizeof(struct ListNode));
            cur1->next->val = 1;
            return l1;
        }
        cur1 = cur1->next;
        cur2 = cur2->next;
    }
    while (carry && cur1) {
        int tmp = cur1->val;
        cur1->val = (carry + tmp) % 10;
        carry = (carry + tmp) / 10;
        if (carry && !cur1->next) {
            cur1->next = calloc(1, sizeof(struct ListNode));
            cur1->next->val = 0;
        }
        cur1 = cur1->next;
    }
    return len1 >= len2 ? l1 : l2;
}