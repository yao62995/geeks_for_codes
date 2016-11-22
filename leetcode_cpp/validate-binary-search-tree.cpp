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
    bool isValidBST(TreeNode *root) {
        if (root == NULL) {
            return true;
        }
        int min, max;
        bool res = isValid(root, min, max);
        return res;
    }
    // node min and max
    // value()
    // return true when current sub tree is valid
    bool isValid(TreeNode* node, int& min, int& max) {
        if (node->left == NULL && node->right == NULL) {
            min = max = node->val;
            return true;
        }
        int left_min, left_max, right_min, right_max;
        if (node->left != NULL) {
            if (!isValid(node->left, left_min, left_max)) {
                return false;
            }
            if (node->val <= left_max) {
                return false;
            }
            min = left_min;
        } else {
            min = node->val;
        }
        if (node->right != NULL) {
            if (!isValid(node->right, right_min, right_max)) {
                return false;
            }
            if (node->val >= right_min) {
                return false;
            }
            max = right_max;
        } else {
            max = node->val;
        }
        return true;
    }
};