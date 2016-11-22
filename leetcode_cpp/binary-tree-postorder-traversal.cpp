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
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> result;
        if (root == NULL) {
            return result;
        }
        // _MidTraverse(root, result);
        stack<TreeNode *> _stack;
        _stack.push(root);
        TreeNode *p;
        TreeNode *visited;
        while (!_stack.empty()) {
            p = _stack.top();
            while (p != NULL) {
                _stack.push(p->left);
                p = p->left;
            }
            _stack.pop();
            if (!_stack.empty()) {
                p = _stack.top();
                if (p->right == NULL || visited == p->right) {
                    _stack.pop();
                    result.push_back(p->val);
                    visited = p;
                    _stack.push(NULL);
                } else {
                    _stack.push(p->right);
                }
            }
        }
        
        return result;
    }
};