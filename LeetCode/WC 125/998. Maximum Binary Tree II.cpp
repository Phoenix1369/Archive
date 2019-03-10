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
    int best, val;
public:
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        this->best = -1;
        this->val = val;
        preorder(root);
        if (best == -1) {
            return create(val, root, nullptr);
        }
        return dfs(root);
    }

private:
    TreeNode* create(int val, TreeNode* left, TreeNode* right) {
        // C-style struct initialization
        TreeNode* ret = new TreeNode{val};
        ret->left = left;
        ret->right = right;
        return ret;
    }

    TreeNode* dfs(TreeNode* cur) {
        if (!cur) return nullptr;
        if (cur->val < best) {
            return cur;
        }
        if (cur->val == best) {
            return create(
                best, cur->left, create(
                    this->val, cur->right, nullptr
                )
            );
        }
        return create(
            cur->val, dfs(cur->left), dfs(cur->right)
        );
    }
    void preorder(TreeNode* cur) {
        if (!cur) return;
        preorder(cur->left);
        if (cur->val > this->val) {
            best = cur->val;
        }
        preorder(cur->right);
    }
};
