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
    int longestZigZag(TreeNode* root) {
        best = 0;
        dfs(root, 0);
        return best;
    }

private:
    int dfs(TreeNode* cur, int mask) {
        if (!cur) return -1;
        int lhs = dfs(cur->left, 0);
        int rhs = dfs(cur->right, 1);
        int val = max(lhs, rhs) + 1;
        best = max(val, best);
        return cur->val = ((mask & 1) ? lhs : rhs) + 1;
    }
};
