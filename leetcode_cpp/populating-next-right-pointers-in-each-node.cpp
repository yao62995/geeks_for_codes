/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (root == NULL) {
            return;
        }
        queue<TreeLinkNode *> node_queue;
        node_queue.push(root);
        int level = 1;
        int level_node_num = 1;
        int level_node_i = 1;
        while (!node_queue.empty()) {
            TreeLinkNode *p = node_queue.front();
            node_queue.pop();
            if (level_node_i == level_node_num) {
                p->next = NULL;
                level++;
                level_node_num *= 2;
                level_node_i = 1;
            } else {
                p->next = node_queue.front();
                level_node_i++;
            }
            if (p->left != NULL) {
                node_queue.push(p->left);
            }
            if (p->right != NULL) {
                node_queue.push(p->right);
            }
        }
    }
};