const int MAXD = 6;
const int MAXL = 15;
const int MOD = 1e9+7;
int dp[2][MAXD][MAXL]{ };
//  dp[i][j][k] = Ways to make a sequence of length i ending on value j with a streak of length (k + 1).

class Solution {
public:
    int dieSimulator(int n, vector<int>& rollMax) {
        init();
        
        for (int h = 2; h <= n; ++h) {
            int i = (h & 1);
            for (int a = 0; a < MAXD; ++a) {
                dp[i][a][0] = 0;
                for (int b = 0; b < MAXD; ++b) {
                    for (int k = 0; k < rollMax[b]; ++k) {
                        if (a != b) {
                            dp[i][a][0] = (1LL * dp[i^1][b][k] + dp[i][a][0]) % MOD;
                        } else if (k > 0) {
                            dp[i][a][k] = dp[i^1][a][k-1];
                        }
                    }
                }
            }
        }
        
        int ret = 0;
        for (int j = 0; j < MAXD; ++j) {
            for (int k = 0; k < rollMax[j]; ++k) {
                ret = (1LL * dp[n & 1][j][k] + ret) % MOD;
            }
        }
        return ret;
    }

private:
    void init() {
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < MAXD; ++j) {
                for (int k = 0; k < MAXL; ++k) {
                    dp[i][j][k] = 0;
                }
            }
        }
        for (int j = 0; j < MAXD; ++j) {
            dp[1][j][0] = 1;
        }
    }
};

/*
2
[1,1,2,2,2,3]
2
[1,1,1,1,1,1]
3
[1,1,1,2,2,3]
>> 34
>> 30
>> 181
*/
