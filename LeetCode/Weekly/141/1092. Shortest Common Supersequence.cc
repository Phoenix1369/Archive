#define ALL(x) (x).begin(), (x).end()
const int MAXN = 1005;
int dp[MAXN][MAXN];
string res, s1, s2;

class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        s1 = move(str1);
        s2 = move(str2);
        int A = s1.size();
        int B = s2.size();
        for (int i = 0; i <= A; ++i) {
            for (int j = 0; j <= B; ++j) {
                dp[i][j] = 0;
            }
        }
        for (int i = 0; i <= A; ++i) {
            dp[i][0] = i;
        }
        for (int j = 0; j <= B; ++j) {
            dp[0][j] = j;
        }
        for (int i = 1; i <= A; ++i) {
            for (int j = 1; j <= B; ++j) {
                if (s1[i-1] == s2[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + 1;
                }
            }
        }
        res.clear();
        backtrack(A, B);
        reverse(ALL(res));
        return res;
    }

private:
    void backtrack(int i, int j) {
        if (!i && !j) {
            return;
        }
        if (!i) {
            res.push_back(s2[j-1]);
            return backtrack(i, j-1);
        }
        if (!j) {
            res.push_back(s1[i-1]);
            return backtrack(i-1, j);
        }
        if (s1[i-1] == s2[j-1]) {
            res.push_back(s1[i-1]);
            return backtrack(i-1, j-1);
        }
        if (dp[i-1][j] < dp[i][j-1]) {
            res.push_back(s1[i-1]);
            return backtrack(i-1, j);
        }
        res.push_back(s2[j-1]);
        backtrack(i, j-1);
    }
};
