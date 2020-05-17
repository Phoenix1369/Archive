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
const int MAXN = 2005;
vec<pair<int,int>> A[MAXN];

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        for (int i = 0; i < MAXN; ++i) {
            A[i].clear();
        }
        dfs(root, 0, MAXN/2);
        vec<vec<int>> ret;
        ret.reserve(MAXN);
        for (int i = 0; i < MAXN; ++i) {
            if (A[i].empty()) continue;
            sort(ALL(A[i]));
            vec<int> data;
            data.reserve(A[i].size());
            for (auto p: A[i]) {
                data.push_back(p.second);
            }
            ret.push_back(move(data));
        }
        return ret;
    }

private:
    void dfs(TreeNode* cur, int row, int col) {
        if (!cur) return;
        A[col].emplace_back(row, cur->val);
        dfs(cur->left , row+1, col-1);
        dfs(cur->right, row+1, col+1);
    }
};
