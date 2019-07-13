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
public:
    double maximumAverageSubtree(TreeNode* root) {
        auto res = dfs(root);
        return 1.0 * res[2] / res[3];
    }

private:
    // return: { sum, sze, bsum, bsze }
    vector<int> dfs(TreeNode* cur) {
        int v = cur->val;
        int s = 1;
        if (!cur->left && !cur->right) {
            return {v, s, v, s};
        }
        int bv = -1;
        int bs = 1;
        if (cur->left) {
            auto lhs = dfs(cur->left);
            v += lhs[0];
            s += lhs[1];
            bv = lhs[2];
            bs = lhs[3];
        }
        if (cur->right) {
            auto rhs = dfs(cur->right);
            v += rhs[0];
            s += rhs[1];
            if (bv * rhs[3] < rhs[2] * bs) {
                bv = rhs[2];
                bs = rhs[3];
            }
        }
        if (bv * s < v * bs) {
            bv = v;
            bs = s;
        }
        return {v, s, bv, bs};
    }
};
