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
    int max_height;
    int maxDepth(TreeNode *root) {
        if (root == NULL) {
            return 0;
        }
        max_height = 0;
        _maxDepth(root, 1);
        return max_height;
    }

    void _maxDepth(TreeNode *node, int height) {
        if (node->left == NULL && node->right == NULL) {  // leaf node
            if (height > max_height) {
                max_height = height;
            }
            return;
        }
        if (node->left != NULL) {
            _maxDepth(node->left, height + 1);
        }
        if (node->right != NULL) {
            _maxDepth(node->right, height + 1);
        }
    }
};