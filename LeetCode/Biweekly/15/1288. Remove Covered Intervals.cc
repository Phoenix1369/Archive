const int MAXN = 1005;
bitset<MAXN> seen;

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int N = intervals.size();
        seen.reset();
        for (int i = 0; i < N; ++i) {
            if (seen[i]) continue;
            int a = intervals[i][0];
            int b = intervals[i][1];
            for (int j = 0; j < N; ++j) {
                if (i == j) continue;
                
                int c = intervals[j][0];
                int d = intervals[j][1];
                if ((c <= a) && (b <= d)) {
                    seen.set(i);
                    break;
                }
            }
        }
        return N - seen.count();
    }
};
