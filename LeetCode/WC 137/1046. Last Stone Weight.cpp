priority_queue<int> pq;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        while (!pq.empty()) pq.pop();
        for (int stone: stones) {
            pq.push(stone);
        }
        while (pq.size() > 1u) {
            int x = pq.top(); pq.pop();
            int y = pq.top(); pq.pop();
            if (x != y) {
                if (x > y) {
                    swap(x, y);
                }
                pq.push(y - x);
            }
        }
        if (!pq.empty()) {
            return pq.top();
        }
        return 0;
    }
};

