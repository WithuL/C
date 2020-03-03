/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* deleteNode(struct ListNode* head, int val) {
    struct ListNode* p = head;
    struct ListNode* q = NULL;
    while (p->val != val)q = p, p = p->next;
    if (q != NULL) q->next = p->next;
    else return p->next;
    return head;
}