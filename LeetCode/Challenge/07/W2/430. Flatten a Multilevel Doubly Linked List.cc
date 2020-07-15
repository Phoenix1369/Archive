/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

Node* src;

class Solution {
public:
    Node* flatten(Node* head) {
        src = new Node{0, nullptr, nullptr, nullptr};
        dfs(head);
        if (head) {
            head->prev = nullptr;
        }
        return head;
    }

private:
    void dfs(Node* cur) {
        // Skip
        if (!cur) {
            return;
        }

        // Append
        src->next = cur;
        cur->prev = src;
        src = cur;

        // Update
        Node* next = cur->next;
        cur->next = cur->child;
        cur->child = nullptr;

        // Advance
        dfs(cur->next);
        dfs(next);
    }
};
