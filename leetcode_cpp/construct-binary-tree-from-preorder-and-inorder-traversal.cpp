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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if (preorder.size() == 0) {
            return NULL;
        }
        TreeNode * root = new TreeNode(preorder[0]);
        _build(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, root);
        return root;
    }

    void _build(vector<int> &preorder, int pbegin, int pend, 
                vector<int> &inorder, int ibegin, int iend, TreeNode * &node) {
        if (pend <= pbegin) {  // leaf
            return;
        }
        int ipos;
        for (ipos = ibegin; ipos <= iend; ipos++) {
            if (node->val == inorder[ipos]) {
                break;
            }
        }
        int left_num = ipos - ibegin;
        int right_num = iend - ipos;
        if (left_num > 0) {
            TreeNode * left_child = new TreeNode(preorder[pbegin + 1]);
            node->left = left_child;
            _build(preorder, pbegin + 1, (pbegin + left_num), inorder, ibegin, (ipos - 1), left_child);
        }
        if (right_num > 0) {
            TreeNode * right_child = new TreeNode(preorder[pbegin + left_num + 1]);
            node->right = right_child;
            _build(preorder, (pbegin + left_num + 1), pend, inorder, (ipos + 1), iend, right_child);
        }
    }
};