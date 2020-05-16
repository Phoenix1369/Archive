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
int cnt;

class Solution {
public:
    int goodNodes(TreeNode* root) {
        cnt = 0;
        dfs(root, root->val);
        return cnt;
    }

private:
    void dfs(TreeNode* cur, int best) {
        if (!cur) return;
        if (cur->val >= best) {
            best = cur->val;
            ++cnt;
        }
        dfs(cur->left, best);
        dfs(cur->right, best);
    }
};
