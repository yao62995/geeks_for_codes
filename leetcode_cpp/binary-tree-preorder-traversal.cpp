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
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> result;
        if (root == NULL) {
            result;
        }
        stack<TreeNode *> _stack;
        _stack.push(root);
        TreeNode * p;
        while (!_stack.empty()) {
            p = _stack.top();
            while (p != NULL) {
                result.push_back(p->val);
                _stack.push(p->left);
                p = p->left;
            }
            _stack.pop();
            if (!_stack.empty()) {
                p = _stack.top();
                _stack.pop();
                _stack.push(p->right);
            }
        }
        return result;
    }
};