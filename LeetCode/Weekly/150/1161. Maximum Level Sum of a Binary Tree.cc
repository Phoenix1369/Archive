/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
const int MAXN = 1e4+5;
int sum[MAXN];

class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        for (int i = 0; i < MAXN; ++i) {
            sum[i] = 0;
        }
        dfs(root, 0);
        int ret = 0;
        for (int i = 0; i < MAXN; ++i) {
            if (sum[i] > sum[ret]) ret = i;
        }
        return ++ret;
    }

private:
    void dfs(TreeNode* cur, int lvl) {
        if (!cur) return;
        sum[lvl] += cur->val;
        dfs(cur->left, lvl + 1);
        dfs(cur->right, lvl + 1);
    }
};
