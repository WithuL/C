/*
����һ����������������е�����k���ڵ㡣Ϊ�˷��ϴ�����˵�ϰ�ߣ������1��ʼ�������������β�ڵ��ǵ�����1���ڵ㡣���磬һ��������6���ڵ㣬��ͷ�ڵ㿪ʼ�����ǵ�ֵ������1��2��3��4��5��6���������ĵ�����3���ڵ���ֵΪ4�Ľڵ㡣

ʾ����
����һ������: 1->2->3->4->5, �� k = 2.
�������� 4->5.
*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* getKthFromEnd(struct ListNode* head, int k) {
    struct ListNode* fast = head;
    struct ListNode* slow = head;
    int i = 1;
    while (fast->next != NULL && i++ < k) fast = fast->next;
    while (fast->next != NULL) {
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
}