#define ALL(x) (x).begin(), (x).end()

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
    vector<TreeNode*> res, ret;

public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        res.clear();
        ret.clear();
        set<int> rem{ALL(to_delete)};
        dfs(root, rem);
        reverse(ALL(ret));
        set<int> skip;
        for (auto node: ret) {
            if (!skip.count(node->val)) {
                res.push_back(node);
            }
            if (node->left) {
                skip.insert(node->left->val);
            }
            if (node->right) {
                skip.insert(node->right->val);
            }
        }
        return res;
    }

private:
    void dfs(TreeNode* cur, const set<int>& rem) {
        if (!cur) return;
        if (cur->left) {
            dfs(cur->left, rem);
            if (rem.count(cur->left->val)) {
                cur->left = nullptr;
            }
        }
        if (cur->right) {
            dfs(cur->right, rem);
            if (rem.count(cur->right->val)) {
                cur->right = nullptr;
            }
        }
        if (!rem.count(cur->val)) {
            ret.push_back(cur);
        }
    }
};
