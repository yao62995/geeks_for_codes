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
    vector<vector<int> > m_Result;

    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        if (root == NULL) {
            return m_Result;
        }
        m_Sum = sum;
        _pathSum(root, 0);
        return m_Result;
    }
    // sum表示从root到node节点的父节点的路径之和
    void _pathSum(TreeNode *node, int sum) {
        static vector<int> path;
        if (node->left == NULL && node->right == NULL) {  // leaf node
            if ((node->val + sum) == m_Sum) {  // check
                path.push_back(node->val);
                m_Result.push_back(path);
                path.pop_back();
                return;
            }
        }
        int new_sum = sum + node->val;
        if (node->left != NULL) {
            path.push_back(node->val);
            _pathSum(node->left, new_sum);
            path.pop_back();
        }
        if (node->right != NULL) {
            path.push_back(node->val);
            _pathSum(node->right, new_sum);
            path.pop_back();
        }
    }
};