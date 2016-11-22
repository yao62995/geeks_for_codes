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
    ListNode *insertionSortList(ListNode *head) {
        ListNode *p1, *p2;
        if (head == NULL) {
            return NULL;
        }
        for (p1 = head; p1->next != NULL; ) {
            for (p2 = head; p2 != p1->next; p2 = p2->next) {
                if (p1->next->val < p2->val) {
                    // break p1 node
                    ListNode *p = p1->next;
                    p1->next = p1->next->next;
                    // connect to p2
                    int tmp = p2->val;
                    p2->val = p->val;
                    p->val = tmp;
                    p->next = p2->next;
                    p2->next = p;
                    break;
                }
            }
            if (p2 == p1->next) {
                p1 = p1->next;
            }
        }
        return head;
    }
};