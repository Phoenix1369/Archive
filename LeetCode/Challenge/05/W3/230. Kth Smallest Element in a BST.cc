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
int K, ret;

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        K = k;
        dfs(root);
        return ret;
    }

private:
    void dfs(TreeNode* cur) {
        if (!cur) return;
        if (!K) return;
        dfs(cur->left);
        if (!K) return;
        if (!--K) ret = cur->val;
        dfs(cur->right);
    }
};
