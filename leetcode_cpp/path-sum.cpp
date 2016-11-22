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
    int m_Sum;

    bool hasPathSum(TreeNode *root, int sum) {
        if (root == NULL) {
            return false;
        }
        m_Sum = sum;
        return _hasPathSum(root, 0);
    }
    // sum表示从root到node节点的父节点的路径之和
    bool _hasPathSum(TreeNode *node, int sum) {
        if (node->left == NULL && node->right == NULL) {  // leaf node
            if ((node->val + sum) == m_Sum) {  // check
                return true;
            }
        }
        int new_sum = sum + node->val;
        if (node->left != NULL) {
            if(_hasPathSum(node->left, new_sum)) {
                return true;
            }
        }
        if (node->right != NULL) {
            if(_hasPathSum(node->right, new_sum)) {
                return true;
            }
        }
        return false;
    }
};