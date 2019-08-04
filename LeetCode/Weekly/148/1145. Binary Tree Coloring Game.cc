/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
const int MAXN = 105;
int sz[MAXN];

class Solution {
    int N, X;
    int ret;

public:
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        for (int i = 1; i <= n; ++i) {
            sz[i] = 0;
        }
        N = n;
        X = x;
        ret = -1;
        dfs(root);
        return (ret != -1);
    }

private:
    void dfs(TreeNode* cur) {
        if (!cur) {
            return;
        }
        ++sz[cur->val];
        if (cur->left) {
            dfs(cur->left);
            sz[cur->val] += sz[cur->left->val];
            check(cur->left, cur->val);
        }
        if (cur->right) {
            dfs(cur->right);
            sz[cur->val] += sz[cur->right->val];
            check(cur->right, cur->val);
        }
    }

    void check(TreeNode* child, int val) {
        // Block parent
        if (child->val == X) {
            if (sz[child->val] * 2 < N) {
                ret = val;
            }
        }
        // Block child
        if (val == X) {
            if (sz[child->val] * 2 > N) {
                ret = child->val;
            }
        }
    }
};
