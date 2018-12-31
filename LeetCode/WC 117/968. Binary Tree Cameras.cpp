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
    enum { HAS, NEED, IS, MOD };
    int ret;

    void dfs(TreeNode* cur) {
        if (cur->left) dfs(cur->left);
        if (cur->right) dfs(cur->right);

        if (!cur->left && !cur->right) {
            cur->val = NEED;
        } else if (cur->left && !cur->right) {
            cur->val = (cur->left->val + 1) % MOD;
        } else if (!cur->left) {
            cur->val = (cur->right->val + 1) % MOD;
        } else {
            set<int> vals{cur->left->val, cur->right->val};
            if (vals.count(NEED)) {
                cur->val = IS;
            } else if (vals.count(IS)) {
                cur->val = HAS;
            } else {
                cur->val = NEED;
            }
        }
        if (cur->val == IS) ++ret;
    }

public:
    int minCameraCover(TreeNode* root) {
        if (!root) return 0;
        ret = 0;
        dfs(root);
        if (root->val == NEED) ++ret;
        return ret;
    }
};
