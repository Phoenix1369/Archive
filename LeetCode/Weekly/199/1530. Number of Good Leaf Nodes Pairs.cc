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

template <typename T>
using vec = vector<T>;
vec<vec<int>> G;
vec<int> H;
int id;

class Solution {
public:
    int countPairs(TreeNode* root, int distance) {
        H.clear();
        G.clear();
        id = 0;
        dfs(root);
        int K = G.size();
        int ret = 0;
        for (int i = 0; i < K; ++i) {
            if (G[i].empty()) {
                continue;
            }
            for (int j = i+1; j < K; ++j) {
                if (G[j].empty()) {
                    continue;
                }
                int a = G[i].size();
                int b = G[j].size();
                --a;
                --b;
                int k = std::min(a, b);
                --k;
                while (k && (G[i][k] != G[j][k])) --k;
                int d = a + b - 2*k;
                if (d <= distance) {
                    ++ret;
                }
            }
        }
        return ret;
    }

private:
    void dfs(TreeNode* cur) {
        if (!cur) {
            return;
        }
        cur->val = id++;
        H.push_back(cur->val);
        G.emplace_back();
        if (cur->left || cur->right) {
            dfs(cur->left);
            dfs(cur->right);
        } else {
            // Leaf
            G[cur->val] = H;
        }
        H.pop_back();
    }
};
