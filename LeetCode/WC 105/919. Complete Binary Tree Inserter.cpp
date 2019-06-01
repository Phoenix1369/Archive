/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class CBTInserter {
    TreeNode* root;
    int size;
    vector<int> path;
public:
    CBTInserter(TreeNode* root) : root{root} {
        size = 0;
        dfs(root);
    }   // Assume non-null
    
    int insert(int v) {
        path.clear();
        int M = ++size;
        while (M) {
            path.push_back(M & 1);
            M >>= 1;
        }
        path.pop_back();
        return dfs2(root, 1, v);
    }
    
    TreeNode* get_root() {
        return root;
    }

private:
    void dfs(TreeNode* cur) {
        if (!cur) return;
        ++size;
        dfs(cur->left);
        dfs(cur->right);
    }

    int dfs2(TreeNode* cur, int pos, int v) {
        int bit = path.back();
        int nxt = pos << 1 | bit;
        path.pop_back();
        if (path.empty()) {
            if (!bit) {
                cur->left = new TreeNode{v};
            } else {
                cur->right = new TreeNode{v};
            }
            return cur->val;
        }
        if (!bit) {
            return dfs2(cur->left, nxt, v);
        }
        return dfs2(cur->right, nxt, v);
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(v);
 * TreeNode* param_2 = obj->get_root();
 */
