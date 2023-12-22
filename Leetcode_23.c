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

    struct ListNode *mergedHead, *cur1, *cur2, *mergedTail;
    cur1 = list1;
    cur2 = list2;
    if (cur1->val < cur2->val) {
        mergedHead = cur1;
        mergedTail = cur1;
        cur1 = cur1->next;
    } else {
        mergedHead = cur2;
        mergedTail = cur2;
        cur2 = cur2->next;
    }

    while(cur1 && cur2) {
        if (cur1->val < cur2->val) {
            mergedTail->next = cur1;
            mergedTail = mergedTail->next;
            cur1 = cur1->next;
        } else {
            mergedTail->next = cur2;
            mergedTail = mergedTail->next;
            cur2 = cur2->next;
        }
    }

    if (cur1)
        mergedTail->next = cur1;
    if (cur2)
        mergedTail->next = cur2;

    return mergedHead;
}

struct ListNode *merge(struct ListNode **lists, int begin, int end) {
    if (begin > end)
        return NULL;
    if (begin == end)
        return lists[begin];
    struct ListNode *left = merge(lists, begin, (begin+end)/2);
    struct ListNode *right = merge(lists, (begin+end)/2 + 1, end);

    return mergeTwoLists(left, right);
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    return merge(lists, 0, listsSize - 1);
}