/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
const vector<int> BAD = {-1};

class Solution {
    int idx;
    vector<int> ret, v;

    bool dfs(TreeNode* cur) {
        if (!cur) return true;
        if (idx >= v.size()) return true;
        if (cur->val != v[idx]) return false;
        ++idx;
        if (dfs(cur->left)) {
            return dfs(cur->right);
        }
        ret.push_back(cur->val);
        return dfs(cur->right) && dfs(cur->left);
    }

public:
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        idx = 0;
        ret.clear();
        v = move(voyage);
        return dfs(root) ? ret : BAD;
    }
};
