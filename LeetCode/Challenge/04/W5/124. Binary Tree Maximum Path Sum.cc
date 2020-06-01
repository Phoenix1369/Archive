/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
int best;

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        best = root->val;
        dfs(root);
        return best;
    }

private:
    int dfs(TreeNode* cur) {
        if (!cur) {
            return 0;
        }
        int lhs = dfs(cur->left);
        int rhs = dfs(cur->right);
        
        int sub = max(max(lhs, rhs), 0);
        int val = cur->val + max(lhs + rhs, sub);
        best = max(val, best);
        return cur->val + sub;
    }
};
