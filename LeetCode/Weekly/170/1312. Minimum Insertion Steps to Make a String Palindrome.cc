const int MAXN = 505;
int dp[MAXN][MAXN];
string S;
int N;

class Solution {
public:
    int minInsertions(string s) {
        S = move(s);
        N = S.size();
        int ret = N;
        init();
        for (int i = 0; i < N; ++i) {
            ret = min(solve(i, i), ret);
            if (i+1 >= N) continue;
            ret = min(solve(i, i+1), ret);
        }
        return ret;
    }

private:
    int solve(int lo, int hi) {
        if (lo < 0) return N - hi;
        if (hi >= N) return lo + 1;
        if (dp[lo][hi] != MAXN) {
            return dp[lo][hi];
        }
        if (S[lo] == S[hi]) {
            return dp[lo][hi] = solve(lo-1, hi+1);
        }
        return dp[lo][hi] = min(solve(lo-1, hi), solve(lo, hi+1)) + 1;
    }
    
    void init() {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                dp[i][j] = MAXN;
            }
        }
    }
};

/*
"zzazz"
"mbadm"
"leetcode"
"g"
"no"
"atac"
"cata"
>> 0
>> 2
>> 5
>> 0
>> 1
*/
