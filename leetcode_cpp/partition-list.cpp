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
    ListNode *partition(ListNode *head, int x) {
        if (head == NULL) {
            return NULL;
        }
        ListNode *head1, *head2;
        ListNode *tail1, *tail2;
        head1 = head2 = NULL;
        ListNode *pre, *p;
        p = head;
        while (p != NULL) {
            pre = p;
            p = p->next;
            if (pre->val < x) {
                if (head1 == NULL) {
                    tail1 = head1 = pre;
                } else {
                    tail1->next = pre;
                    tail1 = pre;
                }
            } else {
                if (head2 == NULL) {
                    tail2 = head2 = pre;
                } else {
                    tail2->next = pre;
                    tail2 = pre;
                }
            }
        }
        if (head1 != NULL) {
            if (head2 != NULL) {
                tail1->next = head2;
                tail2->next = NULL;
            }
        } else {
            head1 = head2;
        }
        return head1;
    }
};