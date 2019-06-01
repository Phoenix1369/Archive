/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#define x first
#define y second
typedef pair<int,int> pii;
const int MAXV = 1e5+5;

class Solution {
    int ans;

public:
    int maxAncestorDiff(TreeNode* root) {
        ans = 0;
        dfs(root);
        return ans;
    }

private:
    pii dfs(TreeNode* cur) {
        if (!cur) {
            return {-1, MAXV};
        }
        pii lhs = dfs(cur->left);
        pii rhs = dfs(cur->right);
        int maxval = max(lhs.x, rhs.x);
        if (maxval != -1) {
            ans = max(abs(cur->val - maxval), ans);
        }
        int minval = min(lhs.y, rhs.y);
        if (minval != MAXV) {
            ans = max(abs(cur->val - minval), ans);
        }
        return {max(cur->val, maxval), min(cur->val, minval)};
    }
};
