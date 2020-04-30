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
const int MAXA = 4e4+5;
int best;

struct Data {
    int mn, mx, sum;
    bool B;
};

class Solution {
public:
    int maxSumBST(TreeNode* root) {
        best = 0;
        dfs(root);
        return best;
    }

private:
    Data dfs(TreeNode* cur) {
        if (!cur) return {MAXA, -MAXA, 0, true};
        Data lhs = dfs(cur->left);
        Data rhs = dfs(cur->right);
        int mn = min(lhs.mn, cur->val);
        int mx = max(cur->val, rhs.mx);
        bool B = lhs.B && rhs.B &&
            (lhs.mx < cur->val) && (cur->val < rhs.mn);
        int sum = lhs.sum + cur->val + rhs.sum;
        if (B) {
            best = max(sum, best);
        }
        return {mn, mx, sum, B};
    }
};
