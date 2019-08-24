class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for (int stone: stones) {
            pq.push(stone);
        }
        while (pq.size() > 1u) {
            int x = pq.top(); pq.pop();
            int y = pq.top(); pq.pop();
            if (x == y) continue;
            if (x > y) swap(x, y);
            pq.push(y - x);
        }
        if (pq.empty()) return 0;
        return pq.top();
    }
};
