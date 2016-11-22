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
    bool isBalanced(TreeNode *root) {
        bool balanced = true;
        _isBalanced(root, &balanced);
        return balanced;
    }

    // left_height：node的左子树高度，right_height:node的右子树高度
    // height: node从下往上的高度
    int _isBalanced(TreeNode *node, bool *balanced) {
        /*if (node->left == NULL && node->right == NULL) {  // left leaf
            return 1;
        }*/
        if (node == NULL) {
            return 0;
        }
        int left_height, right_height;
        left_height = _isBalanced(node->left, balanced);
        if (!balanced) {
            return 0;
        }
        right_height = _isBalanced(node->right, balanced);
        if (!balanced) {
            return 0;
        }
        if (abs(left_height - right_height) > 1) {
            *balanced = false;
            return 0;
        }
        int max = left_height > right_height ? left_height : right_height;
        return (max + 1);
    }
};