/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if (l1 == NULL) {
            return l2;
        } else if (l2 == NULL) {
            return l1;
        }
        ListNode *p1, *pre1, *p2;
        if (l1->val <= l2->val) {
            p1 = l1;
            p2 = l2;
        } else {
            p1 = l2;
            p2 = l1;
        }
        ListNode *l3 = p1;
        while (p1 != NULL && p2 != NULL) {
            if (p1->val <= p2->val) {
                pre1 = p1;
                p1 = p1->next;
            } else {
                ListNode *tmp = p2;
                p2 = p2->next;
                pre1->next = tmp;
                tmp->next = p1;
                pre1 = pre1->next;
            }
        }
        if (p1 == NULL) {
            pre1->next = p2;
        }
        return l3;
    }
};