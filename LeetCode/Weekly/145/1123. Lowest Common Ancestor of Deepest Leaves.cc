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
    int depth;
    TreeNode* ret;
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        depth = 0;
        dfs(root, 0);
        dfs2(root, 0);
        return ret;
    }

private:
    void dfs(TreeNode* cur, int d) {
        if (!cur) {
            return;
        }
        depth = max(d, depth);
        dfs(cur->left, d+1);
        dfs(cur->right, d+1);
    }

    bool dfs2(TreeNode* cur, int d) {
        if (!cur) {
            return false;
        }
        if (d == depth) {
            ret = cur;
            return true;
        }
        bool lhs = dfs2(cur->left, d+1);
        bool rhs = dfs2(cur->right, d+1);
        if (lhs && rhs) {
            ret = cur;
            return true;
        }
        return (lhs || rhs);
    }
};
