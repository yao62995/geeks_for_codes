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
    ListNode *reverseKGroup(ListNode *head, int k) {
        if (head == NULL || head->next == NULL || k <= 1) {
            return head;
        }
        ListNode *pre, *tail, *p, *tmp;
        ListNode* null_head = new ListNode(0);
        null_head->next = head;
        pre = null_head;
        while (pre->next != NULL) {
            int i = 1;
            tail = pre->next;
            p = tail->next;
            while (p != NULL && i < k) {
                tmp = p;
                p = p->next;
                tmp->next = pre->next;
                pre->next = tmp;
                i++;
            }
            if (i < k) { // to the end, restore the last group
                tail->next = NULL;
                tail = pre->next;
                p = pre->next->next;
                while (p != NULL) {
                    tmp = p;
                    p = p->next;
                    tmp->next = pre->next;
                    pre->next = tmp;
                }
                tail->next = NULL;
                break;
            } else {
                tail->next = p;
                pre = tail;
            }
        }
        ListNode* res = null_head->next;
        delete null_head;
        return res;
    }
};