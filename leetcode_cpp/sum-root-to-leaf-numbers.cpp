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
    int m_AllPathSum;
    int m_SinglePathSum;

    int sumNumbers(TreeNode *root) {
        if (root == NULL) {
            return 0;
        }
        m_AllPathSum = 0;
        m_SinglePathSum = 0;
        InorderTraverse(root);
        return m_AllPathSum;
    }

    void InorderTraverse(TreeNode* node) {
        if (node->left == NULL && node->right == NULL) {
            m_SinglePathSum *= 10;
            m_SinglePathSum += node->val;
            m_AllPathSum += m_SinglePathSum;
            m_SinglePathSum /= 10;
            return;
        }
        m_SinglePathSum *= 10;
        m_SinglePathSum += node->val;
        if (node->left != NULL) {
            InorderTraverse(node->left);
        }
        if (node->right != NULL) {
            InorderTraverse(node->right);
        }
        m_SinglePathSum /= 10;
    }
};