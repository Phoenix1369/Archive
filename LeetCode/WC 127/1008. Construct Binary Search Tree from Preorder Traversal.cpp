/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#define ALL(x) (x).begin(), (x).end()

class Solution {
    vector<int> pre;
    int N, pos;
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        pre = move(preorder);
        N = pre.size();
        pos = 0;
        return dfs(*max_element(ALL(pre)) + 1);
    }

private:
    TreeNode* dfs(int up) {
        if (pos >= N) {
            return nullptr;
        }
        TreeNode *ret = new TreeNode{pre[pos]};
        ++pos;
        if ((pos < N) && (pre[pos] < ret->val)) {
            ret->left = dfs(ret->val);
        }
        if ((pos < N) && (pre[pos] < up)) {
            ret->right = dfs(up);
        }
        return ret;
    }
};
