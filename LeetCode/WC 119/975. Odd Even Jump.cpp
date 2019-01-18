const int MAXN = 2e4+5;
std::map<int,int> look;
bool dp[MAXN][2];
int n;

template <typename T> void below(int i, T& itr) {
    if (itr != look.begin()) {
        --itr;
        dp[i][0] = dp[itr->second][1];
    }
}

class Solution {
public:
    int oddEvenJumps(vector<int>& A) {
        n = A.size();
        for (int i = 0; i < n; ++i)
        for (int j = 0; j < 2; ++j) {
            dp[i][j] = false;
        }
        dp[n-1][0] = dp[n-1][1] = true;
        look.clear();
        look[A[n-1]] = n-1;

        int ret = 1;
        for (int i = n-2; i >= 0; --i) {
            auto itr = look.lower_bound(A[i]);
            if (itr != look.end()) {
                dp[i][1] = dp[itr->second][0];
                if (itr->first > A[i]) {
                    below(i, itr);
                } else {
                    dp[i][0] = dp[itr->second][1];
                }
            } else {
                below(i, itr);
            }
            if (dp[i][1]) ++ret;
            // Update
            look[A[i]] = i;
        }
        return ret;
    }
};
