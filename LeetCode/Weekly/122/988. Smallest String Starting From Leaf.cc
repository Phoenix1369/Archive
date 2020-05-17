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
string best;

class Solution {
public:
    string smallestFromLeaf(TreeNode* root) {
        best = "";
        dfs(root, "");
        return best;
    }

private:
    void dfs(TreeNode* cur, string path) {
        if (!cur) return;
        path += 'a' + cur->val;
        if (!cur->left && !cur->right) {
            reverse(ALL(path));
            if (best.empty() || (path < best)) {
                best = path;
            }
        } else {
            dfs(cur->left , path);
            dfs(cur->right, path);
        }
    }
};
