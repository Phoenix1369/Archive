/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
const int MAXN = 5005;

class Solution {
    unordered_set<int> seen;
    int K;
    
public:
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        seen.clear();
        seen.reserve(MAXN);
        K = target;
        dfs(root1);
        return dfs2(root2);
    }

private:
    void dfs(TreeNode* cur) {
        if (!cur) return;
        seen.insert(cur->val);
        dfs(cur->left);
        dfs(cur->right);
    }
    
    bool dfs2(TreeNode* cur) {
        if (!cur) {
            return false;
        }
        if (seen.count(K - cur->val)) {
            return true;
        }
        return dfs2(cur->left) || dfs2(cur->right);
    }
};
