/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head){
    if (!head || !head->next)
        return head;
    
    struct ListNode *new_head = head->next;
    struct ListNode *cnode, *nnode, *pnode;
    struct ListNode *fnode;
    cnode = head;
    pnode = NULL;
    while (cnode && cnode->next) {
        nnode = cnode->next;
        fnode = nnode->next;
        if (fnode)
            cnode->next = fnode->next;
        else
            cnode->next = NULL;
        nnode->next = cnode;
        cnode = fnode;
    }
    return new_head;
}