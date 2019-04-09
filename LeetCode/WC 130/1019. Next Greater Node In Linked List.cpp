/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#define ALL(x) (x).begin(), (x).end()

class Solution {
    set<int> seen;
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> vals;
        for (; head != NULL; head = head->next) {
            vals.push_back(head->val);
        }
        seen.clear();
        vector<int> res;
        for (auto itr = vals.rbegin(); itr != vals.rend(); ++itr) {
            auto jtr = seen.upper_bound(*itr);
            if (jtr == seen.end()) {
                res.push_back(0);
            } else {
                res.push_back(*jtr);
            }
            while (!seen.empty() && (*seen.begin() < *itr)) {
                seen.erase(seen.begin());
            }
            seen.insert(*itr);
        }
        reverse(ALL(res));
        return res;
    }
};
