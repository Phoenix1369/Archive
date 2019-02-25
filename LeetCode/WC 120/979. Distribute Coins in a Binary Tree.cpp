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
    vector<int> val;
public:
    int distributeCoins(TreeNode* root) {
        ret = 0;
        val.clear();
        dfs(root);
        return ret;
    }
    
    int dfs(TreeNode* cur) {
        val.push_back(0);
        if (!cur) return 0;
        int sub = 1;
        sub += dfs(cur->left);
        sub += dfs(cur->right);
        int v = val.back() + val.end()[-2] + cur->val;
        val.pop_back();
        val.pop_back();
        val.back() = v;
        ret += std::abs(v - sub);
        return sub;
    }
};
