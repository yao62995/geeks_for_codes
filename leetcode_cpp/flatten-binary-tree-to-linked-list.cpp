/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    queue<TreeNode *> queue_node;

    void flatten(TreeNode *root) {
        if (root == NULL) {
            return;
        }
        PreTraverse(root);
        TreeNode* p, *next;
        while (!queue_node.empty()) {
            p = queue_node.front();
            queue_node.pop();
            p->left = NULL;
            if (queue_node.empty()) {
                p->right = NULL;
            } else {
                next = queue_node.front();
                p->right = next;
            }
        }
    }

    void PreTraverse(TreeNode* node) {
        if (node != NULL) {
            queue_node.push(node);
            PreTraverse(node->left);
            PreTraverse(node->right);
        }
    }
};