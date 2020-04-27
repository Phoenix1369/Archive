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
typedef long long lld;
vector<int> S;

class Solution {
public:
    int maxProduct(TreeNode* root) {
        S.clear();
        dfs(root);
        lld ret = 0LL;
        int total = S.back();
        for (auto& s: S) {
            ret = max(1LL * s * (total - s), ret);
        }
        return ret % MOD;
    }

private:
    int dfs(TreeNode* cur) {
        if (!cur) {
            return 0;
        }
        int l = dfs(cur->left);
        int r = dfs(cur->right);
        int sum = cur->val + l + r;
        S.push_back(sum);
        return sum;
    }
};
