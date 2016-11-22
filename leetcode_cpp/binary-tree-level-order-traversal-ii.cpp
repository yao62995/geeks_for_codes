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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int> > result;
        if (root == NULL) {
            return result;
        }
        queue<TreeNode *> node_queue;
        queue<int> level_queue;
        node_queue.push(root);
        level_queue.push(0);
        vector<int> empty_vect;
        while (!node_queue.empty()) {
            TreeNode* cur_node = node_queue.front();
            node_queue.pop();
            int cur_level = level_queue.front();
            level_queue.pop();
            if (cur_level >= result.size()) {
                result.insert(result.begin(), empty_vect);
            }
            result[0].push_back(cur_node->val);
            if (cur_node->left != NULL) {
                node_queue.push(cur_node->left);
                level_queue.push(cur_level + 1);
            }
            if (cur_node->right != NULL) {
                node_queue.push(cur_node->right);
                level_queue.push(cur_level + 1);
            }
        }
        return result;
    }
};