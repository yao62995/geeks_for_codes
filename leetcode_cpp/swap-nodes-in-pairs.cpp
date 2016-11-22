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
    ListNode *swapPairs(ListNode *head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode *pre, *p1, *p2, *next;
        p1 = head;
        p2 = head->next;
        p1->next = p2->next;
        p2->next = p1;
        head = p2;
        pre = p1;
        while (pre->next != NULL) {
            p1 = pre->next;
            p2 = p1->next;
            if (p2 == NULL) {
                break;
            }
            next = p2->next;
            pre->next = p2;
            p2->next = p1;
            p1->next = next;
            pre = p1;
        }
        return head;
    }
};