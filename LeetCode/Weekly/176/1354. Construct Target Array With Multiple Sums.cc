typedef long long lld;

class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue<int> pq;
        lld sum = 0;
        for (int x: target) {
            pq.push(x);
            sum += x;
        }
        while (pq.top() > 1) {
            int cur = pq.top();
            pq.pop();
            
            lld rem = sum - cur;
            if (rem == 0) {
                return false;
            }
            if (cur <= rem) {
                return false;
            }
            lld one = (cur - rem) % rem;
            sum = rem + one;
            pq.push(one);
        }
        return true;
    }
};
