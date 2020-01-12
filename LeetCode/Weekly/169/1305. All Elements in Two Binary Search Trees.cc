/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> order;

class Solution {
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        order.clear();
        dfs(root1);
        vector<int> one = move(order);
        dfs(root2);
        vector<int> two = move(order);
        vector<int> ret;
        int N = one.size();
        int M = two.size();
        int i = 0;
        int j = 0;
        while ((i < N) && (j < M)) {
            if (one[i] < two[j]) {
                ret.push_back(one[i++]);
            } else {
                ret.push_back(two[j++]);
            }
        }
        while (i < N) ret.push_back(one[i++]);
        while (j < M) ret.push_back(two[j++]);
        return ret;
    }

private:
    void dfs(TreeNode* cur) {
        if (!cur) {
            return;
        }
        dfs(cur->left);
        order.push_back(cur->val);
        dfs(cur->right);
    }
};
