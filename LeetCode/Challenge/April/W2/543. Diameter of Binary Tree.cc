/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int D;

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        D = 0;
        dfs(root);
        return D;
    }

private:
    int dfs(TreeNode* cur) {
        if (!cur) {
            return -1;
        }
        int lhs = dfs(cur->left);
        int rhs = dfs(cur->right);
        D = max(lhs + rhs + 2, D);
        return max(lhs, rhs) + 1;
    }
};
