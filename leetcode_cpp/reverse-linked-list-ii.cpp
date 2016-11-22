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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if (head == NULL) {
            return NULL;
        }
        if (m == n) {
            return head;
        }
        int pi = 1;
        ListNode *cur, *pre;
        cur = head;
        pre = NULL;
        while (cur != NULL && pi < m) {
            pre = cur;
            cur = cur->next;
            pi++;
        }
        if (cur->next == NULL) {  // when m = length
            return head;
        }
        ListNode* empty_head;
        if (m == 1) {  // when m = 1
            empty_head = new ListNode(0);
            empty_head->next = head;
        } else {
            empty_head = pre;
        }
        cur = cur->next;
        pi++;
        ListNode *tail = empty_head->next;
        while (cur != NULL && pi <= n) {
            ListNode *tmp = cur;
            cur = cur->next;
            pi++;
            tmp->next = empty_head->next;
            empty_head->next = tmp;
        }
        tail->next = cur;
        if (m == 1) {
            head = empty_head->next;
            delete empty_head;
        }
        return head;
    }
};