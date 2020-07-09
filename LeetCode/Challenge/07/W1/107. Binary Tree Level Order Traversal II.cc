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

#define ALL(x) (x).begin(), (x).end()

template <typename T>
using vec = vector<T>;
vec<vec<int>> ret;

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        ret.clear();
        dfs(root, 0);
        reverse(ALL(ret));
        return ret;
    }

private:
    void dfs(TreeNode* cur, unsigned lvl) {
        if (!cur) return;
        if (ret.size() == lvl) {
            ret.emplace_back();
        }
        ret[lvl].push_back(cur->val);
        ++lvl;
        dfs(cur->left , lvl);
        dfs(cur->right, lvl);
    }
};
