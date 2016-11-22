/**
 * Definition for singly-linked list with a random pointer.
     * struct RandomListNode {
     *     int label;
     *     RandomListNode *next, *random;
     *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
     * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == NULL) {
            return NULL;
        }
        RandomListNode *head_new, *tail_new;
        head_new = tail_new = NULL;
        RandomListNode *p_old, *p_new;
        map<RandomListNode*, vector<int> > map_pi; // <random_pointer, index> for old one 
        vector<RandomListNode *> map_ip;   // <index, pointer> for new one
        map<RandomListNode*, vector<int> >::iterator iter;
        int index = 0;
        // make as single link list
        for (p_old = head; p_old != NULL; p_old = p_old->next) {
            p_new = new RandomListNode(p_old->label);
            if (head_new == NULL) {
                tail_new = head_new = p_new;
            } else {
                tail_new->next = p_new;
                tail_new = p_new;
            }
            map_ip.push_back(p_new);
            if (p_old->random != NULL) {
                iter = map_pi.find(p_old->random);
                if (iter == map_pi.end()) {
                    vector<int> idx;
                    idx.push_back(index);
                    map_pi.insert(make_pair(p_old->random, idx));
                } else {
                    iter->second.push_back(index);
                }
                
            }
            index++;
        }
        // add random pointer for new one
        index = 0;
        int index2;
        for (p_old = head; p_old != NULL; p_old = p_old->next) {
            iter = map_pi.find(p_old);
            if (iter != map_pi.end()) {
                vector<int>& idx = iter->second;
                for (int i = 0; i < idx.size(); i++) {
                    index2 = idx[i];
                    map_ip[index2]->random = map_ip[index];
                }
            }
            index++;
        }
        return head_new;
    }
};