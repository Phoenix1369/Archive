/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
const int MAXN = 1005;
unordered_map<int, ListNode*> seen;

class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        seen.clear();
        seen.reserve(MAXN);
        
        ListNode* cur = new ListNode(0);
        cur->next = head;
        
        int sum = 0;
        while (cur) {
            sum += cur->val;
            if (seen.count(sum)) {
                ListNode* prev = seen.at(sum);
                int val = sum;
                
                while (prev->next != cur) {
                    prev = prev->next;
                    val += prev->val;
                    seen.erase(val);
                }
                seen.at(sum)->next = cur->next;
            } else {
                seen[sum] = cur;
            }
            cur = cur->next;
        }
        return seen.at(0)->next;
    }
};
