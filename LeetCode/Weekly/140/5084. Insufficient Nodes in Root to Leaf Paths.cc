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
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        return dfs(root, limit, 0);
    }

private:

    TreeNode* dfs(TreeNode* cur, int limit, int sum) {
        if (!cur) return cur;
        
        sum += cur->val;
        if (!cur->left && !cur->right) {
            if (sum < limit) {
                return nullptr;
            }
            return cur;
        }

        cur->left = dfs(cur->left, limit, sum);
        cur->right = dfs(cur->right, limit, sum);
        if (!cur->left && !cur->right) {
            return nullptr;
        }
        return cur;
    }
};
