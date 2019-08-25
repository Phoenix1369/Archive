class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        priority_queue<int> pq;
        for (auto s: sticks) {
            pq.push(-s);
        }
        int cost = 0;
        while (pq.size() > 1u) {
            int X = pq.top(); pq.pop();
            int Y = pq.top(); pq.pop();
            int sum = X + Y;
            cost -= sum;
            pq.push(sum);
        }
        return cost;
    }
};
