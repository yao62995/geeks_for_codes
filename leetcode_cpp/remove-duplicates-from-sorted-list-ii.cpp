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
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == NULL) {
            return NULL;
        }
        ListNode *p1, *p2;
        ListNode *pre1, *first;
        pre1 = head;
        p1 = head->next;
        // find the first unique one, make sure the new head
        while (p1 != NULL) {
            while (p1 != NULL && p1->val == pre1->val) {
                pre1 = p1;
                p1 = p1->next;
            }
            if (pre1 == head) {  // a unique one
                break;
            }
            if (p1 == NULL) {
                return NULL;
            } else {
                head = p1;
                pre1 = head;
                p1 = head->next;
            }
        }
        // continue to remove
        if (head->next == NULL) {
            return head;
        }
        p2 = head;
        while (p1 != NULL) {
            pre1 = p2->next;
            p1 = pre1->next;
            first = pre1;
            while (p1 != NULL && p1->val == pre1->val) {
                pre1 = p1;
                p1 = p1->next;
            }
            if (pre1 == first) {  // a unique one
                p2->next = first;
                p2 = p2->next;
                if (p2->next == NULL) {
                    return head;
                }
            } else {
                p2->next = p1;
            }
        }
        return head;
    }
};