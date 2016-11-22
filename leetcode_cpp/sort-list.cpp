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
    ListNode *sortList(ListNode *head) {
        if (head == NULL) {
            return NULL;
        }
        ListNode* null_head = new ListNode(0);
        null_head->next = head;
        partition(null_head, NULL);
        head = null_head->next;
        delete null_head;
        return head;
    }

    // head, tail is not used
    void partition(ListNode* head, ListNode* tail) {
        if (head->next == tail || head->next->next == tail) {
            return;
        }
        ListNode* pivot = head->next;
        // list1 < pivot, list2 > pivot, list3 = pivot
        ListNode *list1, *list2, *list3, *p, *p1, *p2, *p3;
        list1 = list2 = list3 = NULL;
        p = pivot->next;
        while (p != tail) {
            if (p->val > pivot->val) {
                if (list2 == NULL) {
                    p2 = list2 = p;
                } else {
                    p2->next = p;
                    p2 = p;
                }
            } else if (p->val < pivot->val) {
                if (list1 == NULL) {
                    p1 = list1 = p;
                } else {
                    p1->next = p;
                    p1 = p;
                }
            } else {
                if (list3 == NULL) {
                    p3 = list3 = p;
                } else {
                    p3->next = p;
                    p3 = p;
                }
            }
            p = p->next;
        }
        if (list1 != NULL) {
            head->next = list1;
            p1->next = pivot;
        } else {
            head->next = pivot;
        }
        if (list3 != NULL) {
            pivot->next = list3;
            pivot = p3;
        }
        if (list2 != NULL) {
            pivot->next = list2;
            p2->next = tail;
        } else {
            pivot->next = tail;
        }
        if (list3 != NULL) {
            partition(head, list3);
            partition(p3, tail);
        } else {
            partition(head, pivot);
            partition(pivot, tail);
        }
    }
};