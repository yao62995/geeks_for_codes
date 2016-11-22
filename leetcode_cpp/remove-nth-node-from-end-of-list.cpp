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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if (head == NULL || n <= 0) {
            return head;
        }
        ListNode *p1, *p2;
        int half = 0, total;
        p1 = p2 = head;
        while (p2 != NULL && p2->next != NULL) {
            half++;
            p1 = p1->next;
            p2 = p2->next->next;
        }
        if (p2 == NULL) {
            total = half * 2;
        } else {
            total = half * 2 + 1;
        }
        int m = total - n + 1;  // from the begin
        int cur = half + 1;
        ListNode *pre;
        if (cur < m) { // continue
            while (cur++ < m) {
                pre = p1;
                p1 = p1->next;
            }
            pre->next = p1->next;
        } else { // from begin
            if (m == 1) {  // first node
                return head->next;
            }
            cur = 1;
            p1 = head;
            while (cur++ < m) {
                pre = p1;
                p1 = p1->next;
            }
            pre->next = p1->next;
        }
        return head;
    }
};