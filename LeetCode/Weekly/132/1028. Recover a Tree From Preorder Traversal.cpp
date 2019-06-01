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
    string S;
    int ptr;
    
    int dashes() {
        int cnt = 0;
        while ((ptr < S.size()) && (S[ptr] == '-')) {
            ++cnt;
            ++ptr;
        }
        return cnt;
    }
    
    int digits() {
        int num = 0;
        while ((ptr < S.size()) && (S[ptr] != '-')) {
            num = num * 10 + (S[ptr] - '0');
            ++ptr;
        }
        return num;
    }

    TreeNode* dfs(int d) {
        int depth = dashes();
        if (depth != d) {
            ptr -= depth;
            return nullptr;
        }
        TreeNode* cur = new TreeNode{digits()};
        cur->left = dfs(d + 1);
        cur->right = dfs(d + 1);
        return cur;
    }

public:
    TreeNode* recoverFromPreorder(string S) {
        this->S = S;
        this->ptr = 0;
        return dfs(0);
    }
};
