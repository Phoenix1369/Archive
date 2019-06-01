class Solution {
    set<int> seen;

public:
    int smallestRepunitDivByK(int K) {
        seen.clear();
        int cnt = 1;
        int rem = 1 % K;
        while (true) {
            if (rem == 0) {
                return cnt;
            }
            if (seen.count(rem)) {
                return -1;
            }
            seen.insert(rem);
            rem = (rem * 10 + 1) % K;
            ++cnt;
        }
        return -1;
    }
};
