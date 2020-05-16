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
const int MAXN = 100;
int up1[MAXN];
int up2[MAXN];

class Solution {
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        init();
        dfs(root1, up1, -1);
        dfs(root2, up2, -1);
        for (int i = 0; i < MAXN; ++i) {
            if (up1[i] != up2[i]) {
                return false;
            }
        }
        return true;
    }

private:
    void dfs(TreeNode* cur, int* up, int parent) {
        if (!cur) return;
        up[cur->val] = parent;
        dfs(cur->left,  up, cur->val);
        dfs(cur->right, up, cur->val);
    }
    
    void init() {
        for (int i = 0; i < MAXN; ++i) {
            up1[i] = up2[i] = -2;
        }
    }
};
