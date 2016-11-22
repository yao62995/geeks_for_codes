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
    // min heap
    struct _NodeComp {
        bool operator () (ListNode* node1, ListNode* node2) {
            return (node1->val > node2->val);
        }
    } NodeComp;

    ListNode *mergeKLists(vector<ListNode *> &lists) {
        int size = lists.size();
        if (size == 0) {
            return NULL;
        } else if (size == 1) {
            return lists[0];
        }
        int i;
        vector<ListNode *> heap_list;
        for (i = 0; i < lists.size(); i++) {
            if (lists[i] != NULL) {
                heap_list.push_back(lists[i]);
            }
        }
        make_heap(heap_list.begin(), heap_list.end(), NodeComp);
        ListNode * result, *p;
        p = result = NULL;
        while (!heap_list.empty()) {
            ListNode* min = heap_list.front();
            if (result == NULL) {
                p = result = min;
            } else {
                p->next = min;
                p = min;
            }
            
            pop_heap(heap_list.begin(), heap_list.end(), NodeComp);
            heap_list.pop_back();
            if (min->next != NULL) {
                heap_list.push_back(min->next);
                push_heap(heap_list.begin(), heap_list.end(), NodeComp);
            }
        }
        return result;
    }
};