/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    int getDecimalValue(ListNode* head) {
        return dfs(head, 0);
    }
    
private:
    int dfs(ListNode* cur, int val) {
        if (!cur) {
            return val;
        }
        return dfs(cur->next, val << 1 | cur->val);
    }
};

/*
[1,0,1]
[0]
[1]
[1,0,0,1,0,0,1,1,1,0,0,0,0,0,0]
[0,0]
>> 5
>> 0
>> 1
>> 18880
>> 0
*/
