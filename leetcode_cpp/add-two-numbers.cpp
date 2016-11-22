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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        if (l1 == NULL) {
            return l2;
        } else if (l2 == NULL) {
            return l1;
        }
        int added, carry = 0;
        ListNode *p1, *p2, *p3;
        p1 = l1;
        p2 = l2;
        p1->val = p1->val + p2->val;
        if (p1->val >= 10) {
            p1->val = p1->val - 10;
            carry = 1;
        }
        while (p1->next != NULL && p2->next != NULL) {
            added = p1->next->val + p2->next->val + carry;
            if (added >= 10) {
                p1->next->val = added - 10;
                carry = 1;
            } else {
                p1->next->val = added;
                carry = 0;
            }
            p1 = p1->next;
            p2 = p2->next;
        }
        // reconnect
        if (p1->next == NULL) {
            p1->next = p2->next;
        }
        while (carry && p1->next != NULL) {
            added = p1->next->val + carry;
            if (added >= 10) {
                p1->next->val = added - 10;
                carry = 1;
            } else {
                p1->next->val = added;
                carry = 0;
            }
            p1 = p1->next;
        }
        if (p1->next == NULL && carry) {
            ListNode* node = new ListNode(carry);
            p1->next = node;
        }
        return l1;
    }
};