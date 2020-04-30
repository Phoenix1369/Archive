/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
ListNode* front;

class Solution {
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        front = head;
        return dfs(root, front);
    }

private:
    bool dfs(TreeNode* cur, ListNode* pos) {
        if (!pos) return true;
        if (!cur) return false;
        return
            match(cur, front) ||
            dfs(cur->left , front) ||
            dfs(cur->right, front);
    }
    
    bool match(TreeNode* cur, ListNode* pos) {
        if (!pos) return true;
        if (!cur) return false;
        if (cur->val != pos->val) {
            return false;
        }
        return
            match(cur->left , pos->next) ||
            match(cur->right, pos->next);
    }
};
