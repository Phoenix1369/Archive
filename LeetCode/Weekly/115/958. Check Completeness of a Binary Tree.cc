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
struct State {
    int mn, mx;
};
bool complete;

class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        complete = true;
        dfs(root, 0);
        return complete;
    }

private:
    State dfs(TreeNode* cur, int lvl) {
        if (!cur) return {lvl, lvl};
        ++lvl;
        State lhs = dfs(cur->left , lvl);
        State rhs = dfs(cur->right, lvl);
        if ((rhs.mx > lhs.mn) || (lhs.mx > rhs.mn + 1)) {
            complete = false;
        }
        return {min(lhs.mn, rhs.mn), max(lhs.mx, rhs.mx)};
    }
};
