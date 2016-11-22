/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode *sortedListToBST(ListNode *head) {
        ListNode* p = head;
        int count = 0;
        while (p != NULL) {
            count++;
            p = p->next;
        }
        p = head;
        TreeNode *root = _sortedListToBST(p, count);
        return root;
    }

    TreeNode *_sortedListToBST(ListNode *&node, int n) {
        if (n <= 0) {
            return NULL;
        }
        TreeNode* left = _sortedListToBST(node, n / 2);
        TreeNode* root = new TreeNode(node->val);
        root->left = left;
        node = node->next;
        TreeNode* right = _sortedListToBST(node, n - n / 2 - 1);
        root->right = right;
        return root;
    }
};