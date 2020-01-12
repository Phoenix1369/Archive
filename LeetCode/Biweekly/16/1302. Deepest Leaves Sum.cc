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
    int d, depth, ret;

public:
    int deepestLeavesSum(TreeNode* root) {
        d = depth = 0;
        dfs(root);
        ret = 0;
        dfs2(root);
        return ret;
    }

private:
    void dfs(TreeNode* cur) {
        if (!cur) return;
        depth = max(d, depth);
        ++d;
        dfs(cur->left);
        dfs(cur->right);
        --d;
    }
    
    void dfs2(TreeNode* cur) {
        if (!cur) return;
        if (d == depth) {
            ret += cur->val;
        }
        ++d;
        dfs2(cur->left);
        dfs2(cur->right);
        --d;
    }
};
