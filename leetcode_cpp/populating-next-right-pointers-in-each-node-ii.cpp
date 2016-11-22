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
        queue<int> level_queue;
        node_queue.push(root);
        level_queue.push(1);
        while (!node_queue.empty()) {
            TreeLinkNode *p = node_queue.front();
            node_queue.pop();
            int level = level_queue.front();
            level_queue.pop();
            if (level_queue.empty() || level != level_queue.front()) {
                p->next = NULL;
            } else {
                p->next = node_queue.front();
            }
            if (p->left != NULL) {
                node_queue.push(p->left);
                level_queue.push(level + 1);
            }
            if (p->right != NULL) {
                node_queue.push(p->right);
                level_queue.push(level + 1);
            }
        }
    }
};