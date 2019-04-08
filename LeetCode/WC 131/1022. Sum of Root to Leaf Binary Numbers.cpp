/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
const int MOD = 1e9+7;

class Solution {
public:
    int sumRootToLeaf(TreeNode* root) {
        if (!root) return 0;
        return dfs(root, 0);
    }

private:
    int dfs(TreeNode* cur, int sum) {
        // (cur != nullptr)
        sum = (1LL*sum + cur->val) % MOD;
        int ssum = 2LL*sum % MOD;
        if (cur->left && cur->right) {
            return (1LL*dfs(cur->left, ssum) + dfs(cur->right, ssum)) % MOD;
        } else if (cur->left) {
            return dfs(cur->left, ssum);
        } else if (cur->right) {
            return dfs(cur->right, ssum);
        } else {
            return sum;
        }
    }
};
