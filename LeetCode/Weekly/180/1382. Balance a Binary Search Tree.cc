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
vector<int> D;
int N;

class Solution {
public:
    TreeNode* balanceBST(TreeNode* root) {
        D.clear();
        dfs(root);  // inorder
        N = D.size();
        return dfs2(0, N-1);
    }

private:
    void dfs(TreeNode* cur) {
        if (!cur) return;
        dfs(cur->left);
        D.push_back(cur->val);
        dfs(cur->right);
    }
    
    TreeNode* dfs2(int lo, int hi) {
        if (lo > hi) {
            return nullptr;
        }
        if (lo == hi) {
            return new TreeNode(D[lo]);
        }
        int mid = (lo + hi) / 2;
        return new TreeNode(
            D[mid],
            dfs2(lo, mid-1),
            dfs2(mid+1, hi)
        );
    }
};
