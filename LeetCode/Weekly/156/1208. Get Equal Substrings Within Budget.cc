class Solution {    
public:
    int equalSubstring(string s, string t, int maxCost) {
        int N = s.size();
        int K = maxCost;
        
        int best = 0;
        int cost = 0;
        int head = 0;
        for (int i = 0; i < N; ++i) {
            cost += abs(s[i] - t[i]);
            while ((head <= i) && (cost > maxCost)) {
                cost -= abs(s[head] - t[head]);
                ++head;
            }
            best = max(i - head + 1, best);
        }
        return best;
    }
};
