class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        const int MAXN = 1e4+5;
        int cnt[MAXN]{ };
        
        for (int& a: A) {
            if (cnt[a]++) {
                return a;
            }
        }
        // guaranteed
    }
};
