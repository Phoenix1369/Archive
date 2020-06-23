class Solution {
public:
    int hIndex(vector<int>& citations) {
        if (citations.empty() || !citations.back()) {
            return 0;
        }
        int N = citations.size();
        int lo = 1;
        int hi = N;
        while (lo < hi) {
            int x = (lo + hi + 1) / 2;
            if (citations[N-x] >= x) {
                lo = x;
            } else {
                hi = x-1;
            }
        }
        return lo;
    }
};
