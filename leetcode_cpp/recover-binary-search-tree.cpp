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
    void recoverTree(TreeNode *root) {
        if (root == NULL) {
            return;
        }
        vector<TreeNode*> target;
        TreeNode *cur, *next;
        cur = next = NULL;
        traverse(root, cur, next, target);
        if (target.size() == 2) {
            swap(target[0], target[1]);
        }
    }

    void traverse(TreeNode *node, TreeNode* &cur, TreeNode* &next, vector<TreeNode*> &target) {
        static bool isOk = false;
        if (isOk) {
            return;
        }
        if (node != NULL) {
            traverse(node->left, cur, next, target);
            if (cur == NULL && next == NULL) {
                next = node;
            } else {
                cur = next;
                next = node;
                if (cur->val > next->val) {
                    if (target.size() == 0) {
                        target.push_back(cur);
                        target.push_back(next);
                    } else {
                        target[1] = next;
                        isOk = true;
                        return;
                    }
                }
            }
            traverse(node->right, cur, next, target);
        }
    }

    void swap(TreeNode* node1, TreeNode* node2) {
        if (node1 != node2) {
            int tmp = node1->val;
            node1->val = node2->val;
            node2->val = tmp;
        }
    }
};