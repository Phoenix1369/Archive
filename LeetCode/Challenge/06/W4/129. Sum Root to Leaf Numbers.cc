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
int sum;

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        sum = 0;
        dfs(root, 0);
        return sum;
    }

private:
    void dfs(TreeNode* cur, int val) {
        if (!cur) {
            return;
        }
        val = val * BASE + cur->val;
        if (cur->left || cur->right) {
            dfs(cur->left , val);
            dfs(cur->right, val);
        } else {
            sum += val;
        }
    }
};
