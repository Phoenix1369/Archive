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
    int dx, dy, px, py;
public:
    bool isCousins(TreeNode* root, int x, int y) {
        dfs(root, -1, 0, x, y);
        return (dx == dy) && (px != py);
    }
    
    void dfs(TreeNode* cur, int up, int d, int x, int y) {
        if (!cur) return;
        if (cur->val == x) {
            dx = d;
            px = up;
        }
        if (cur->val == y) {
            dy = d;
            py = up;
        }
        dfs(cur->left, cur->val, d+1, x, y);
        dfs(cur->right, cur->val, d+1, x, y);
    }
};
