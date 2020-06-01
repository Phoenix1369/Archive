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
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head) {
            return head;
        }
        ListNode* tail = head->next;
        ListNode* C[2] = {head, tail};
        for (int i = 0; C[i]->next; i ^= 1) {
            C[i]->next = C[i^1]->next;
            if (C[i]->next) {
                C[i] = C[i]->next;
            }
        }
        C[0]->next = tail;
        return head;
    }
};
