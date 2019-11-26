/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
const int MAXN = 1e4+5;
unordered_set<int> seen;

class FindElements {
public:
    FindElements(TreeNode* root) {
        seen.clear();
        seen.reserve(MAXN);
        dfs(root, 0);
    }
    
    bool find(int target) {
        return seen.count(target) != 0;
    }

private:
    void dfs(TreeNode* cur, int val) {
        if (!cur) {
            return;
        }
        seen.insert(val);
        dfs(cur->left, 2*val + 1);
        dfs(cur->right, 2*val + 2);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */

/*
["FindElements","find","find"]
[[[-1,null,-1]],[1],[2]]
["FindElements","find","find","find"]
[[[-1,-1,-1,-1,-1]],[1],[3],[5]]
["FindElements","find","find","find","find"]
[[[-1,null,-1,-1,null,-1]],[2],[3],[4],[5]]
>> [null,false,true]
>> [null,true,true,false]
>> [null,true,false,false,true]
*/
