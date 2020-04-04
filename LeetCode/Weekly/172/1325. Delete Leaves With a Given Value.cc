/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    int K;

public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        K = target;
        return dfs(root);
    }

private:
    TreeNode* dfs(TreeNode*& cur) {
        if (!cur) return cur;
        
        dfs(cur->left);
        dfs(cur->right);
        
        if (!cur->left && !cur->right && (cur->val == K)) {
            cur = nullptr;
        }
        return cur;
    }
};
