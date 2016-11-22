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
    int min_depth;

    int minDepth(TreeNode *root) {
        if (root == NULL) {
            return 0;
        }
        min_depth = 0x7FFFFFFF;
        _depth(root, 1);

        return min_depth;
    }

    void _depth(TreeNode * node, int depth) {
        if (node->left == NULL && node->right == NULL) {
            if (depth < min_depth) {
                min_depth = depth;
            }
            return;
        }
        if (node->left != NULL) {
            _depth(node->left, depth + 1);
        }
        if (node->right != NULL) {
            _depth(node->right, depth + 1);
        }
    }
};