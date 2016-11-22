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
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL || head->next == NULL) {
            return NULL;
        }
        if (head->next == head) {
            return head;
        }
        ListNode * p1, *p2;
        p1 = p2 = head;
        while (p2 != NULL && p2->next != NULL) {
            p1 = p1->next;
            p2 = p2->next->next;
            if (p1 == p2) {
                break;
            }
        }
        if (p2 == NULL || p2->next == NULL) {  // no cycle
            return NULL;
        }
        
        p1 = p1->next;
        p2->next = NULL;  // break cycyle
        p2 = head;
        // find first common node from p1 and p2
        ListNode *p3;
        int len_p1, len_p2;
        len_p1 = len_p2 = 0;
        p3 = p1;
        while (p3 != NULL) {
            len_p1++;
            p3 = p3->next;
        }
        p3 = p2;
        while (p3 != NULL) {
            len_p2++;
            p3 = p3->next;
        }
        int diff;
        if (len_p1 > len_p2) {
            diff = len_p1 - len_p2;
            while (diff-- > 0) {
                p1 = p1->next;
            }
        } else {
            diff = len_p2 - len_p1;
            while (diff-- > 0) {
                p2 = p2->next;
            }
        }
        while (p1 != p2) {
            p1 = p1->next;
            p2 = p2->next;
        }
        return p1;
    }
};