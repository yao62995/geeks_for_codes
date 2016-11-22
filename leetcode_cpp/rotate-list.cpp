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
    ListNode *rotateRight(ListNode *head, int k) {
        if (head == NULL || k == 0 || head->next == NULL) {
            return head;
        }
        ListNode * p, *p2, *tail;
        int n = 0;
        p = head;
        while (p != NULL) {
            n++;
            tail = p;
            p = p->next;
        }
        k = k % n;
        if (k == 0) {
            return head;
        }
        int pre = n - k;
        p = head;
        while (pre-- > 0) {
            p2 = p;
            p = p->next;
        }

        if (p == head) {
            return head;
        } 
        p2->next = NULL;
        if (tail != head) {
            tail->next = head;
        }
        head = p;
        return head;
    }
};