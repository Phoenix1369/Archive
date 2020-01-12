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
    int ret;

public:
    int sumEvenGrandparent(TreeNode* root) {
        ret = 0;
        dfs(root, 0);
        return ret;
    }

private:
    void dfs(TreeNode* root, int cur) {
        if (!root) return;
        if (cur & 1) {
            ret += root->val;
        }
        cur >>= 1;
        if ((root->val & 1) == 0) {
            cur |= 2;
        }
        dfs(root->left, cur);
        dfs(root->right, cur);
    }
};
