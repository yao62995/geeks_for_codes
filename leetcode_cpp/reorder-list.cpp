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
    void reorderList(ListNode *head) {
        if (head == NULL || head->next == NULL) {
            return;
        }
        ListNode *p1, *p2, *p3;
        bool isOdd = false;
        p1 = p2 = head;
        while (p2 != NULL && p2->next != NULL) {
            p3 = p1;
            p1 = p1->next;
            p2 = p2->next->next;
        }
        // when node number is odd
        if (p2 != NULL) {
            p3 = p1;
            p1 = p1->next;
            isOdd = true;
        }
        p3->next = NULL;
        // reverse list node from p1
        ListNode *head2 = new ListNode(0);
        while (p1 != NULL) {
            ListNode *tmp = p1;
            p1 = p1->next;
            tmp->next = head2->next;
            head2->next = tmp;            
        }
        // merge two list
        p1 = head;
        p2 = head2->next;
        while (p2 != NULL) {
            ListNode *tmp = p2;
            p2 = p2->next;
            tmp->next = p1->next;
            p1->next = tmp;
            p1 = tmp->next;
        }
        if (isOdd) {
            p1->next = NULL;
        } else {
            p1 = NULL;
        }
        // release 
        delete head2;
        head2 = NULL;
    }
};