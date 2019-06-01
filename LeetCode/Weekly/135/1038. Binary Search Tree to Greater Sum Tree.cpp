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
    TreeNode* bstToGst(TreeNode* root) {
        if (root) {
            dfs(root, 0);
        }
        return root;
    }

private:
    int dfs(TreeNode* cur, int sum) {
        if (cur->right) {
            cur->val += dfs(cur->right, sum);
        }
        if (cur->left) {
            return dfs(cur->left, cur->val);
        }
        if (!cur->left && !cur->right) {
            cur->val += sum;
        }
        return cur->val;
    }
};
