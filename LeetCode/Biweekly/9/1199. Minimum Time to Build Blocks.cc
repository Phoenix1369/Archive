class Solution {
public:
    int minBuildTime(vector<int>& blocks, int split) {
        priority_queue<int> pq;
        for (auto b: blocks) {
            pq.push(-b);
        }
        while (pq.size() > 1u) {
            pq.pop();
            int cur = pq.top();
            pq.pop();
            pq.push(cur - split);
        }
        return -pq.top();
    }   // Huffman coding.
};
