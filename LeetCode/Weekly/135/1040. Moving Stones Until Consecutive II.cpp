#define ALL(x) (x).begin(), (x).end()

class Solution {
    int best, N, size;

public:
    vector<int> numMovesStonesII(vector<int>& stones) {
        sort(ALL(stones));
        N = stones.size();
        best = size = 0;
        for (int i = 0, end = 0; i < N; ++i) {
            while ((end < N) && (stones[end] - stones[i] < N)) ++end;
            int diff = (end - i);
            if (diff >= size) {
                best = i;
                size = diff;
            }
        }
        int da = (stones[1] - stones[0]);
        int db = (stones[N-1] - stones[N-2]);
        int sum = stones[N-1] - stones[0] - (N-1);
        int skip = min(da, db) - 1;
        int maximum = (sum - skip);

        if (size == (N-1)) {
            if ((da == 2) || (db == 2)) {
                return {1, maximum};
            }
            return {2, maximum};
        }
        return {N-size, maximum};
    }
};

/*
1 2 3 4 A
2 3 4 6 A
2 3 4 5 6
--- [2]
1 2 3 4 6
2 3 4 5 6
--- [1]
*/
