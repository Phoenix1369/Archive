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
const int BASE = 10;
vector<int> cnt;
int ret;

class Solution {
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        cnt.assign(BASE, 0);
        ret = 0;
        dfs(root);
        return ret;
    }

private:
    void dfs(TreeNode* cur) {
        if (!cur) return;
        ++cnt[cur->val];
        if (!cur->left && !cur->right) {
            int odd = 0;
            for (int x: cnt) odd += (x & 1);
            if (odd <= 1) ++ret;
        } else {
            dfs(cur->left);
            dfs(cur->right);
        }
        --cnt[cur->val];
    }
};
