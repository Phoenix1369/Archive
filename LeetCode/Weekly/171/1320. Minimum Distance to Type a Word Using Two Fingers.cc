const int ALPHA = 26;
const int COLS = 6;
const int MAXN = 305;
const int INFN = ALPHA * MAXN;
int dp[MAXN][ALPHA][ALPHA];
// dp[i][j][k] = i-th character, j-th key (f1), k-th key (f2)
// transition: same or different finger from current to previous key

class Solution {
public:
    int minimumDistance(string word) {
        int N = word.size();
        for (int i = 0; i < ALPHA; ++i) {
            for (int j = 0; j < ALPHA; ++j) {
                dp[0][i][j] = 0;
            }
        }
        for (int i = 1; i < N; ++i) {
            int b = word[i-1]-'A';
            int c = word[i]-'A';
            for (int j = 0; j < ALPHA; ++j) {
                for (int k = 0; k < ALPHA; ++k) {
                    dp[i+1][j][k] = INFN;
                }
            }
            for (int k = 0; k < ALPHA; ++k) {
                dp[i+1][b][c] = min(dp[i][b][k] + diff(c, k), dp[i+1][b][c]);
                dp[i+1][c][b] = min(dp[i][k][b] + diff(c, k), dp[i+1][c][b]);
                dp[i+1][c][k] = min(dp[i][b][k] + diff(b, c), dp[i+1][c][k]);
                dp[i+1][k][c] = min(dp[i][k][b] + diff(b, c), dp[i+1][k][c]);
            }
        }
        int ret = INFN;
        for (int i = 0; i < ALPHA; ++i) {
            for (int j = 0; j < ALPHA; ++j) {
                ret = min(dp[N][i][j], ret);
            }
        }
        return ret;
    }

private:
    int diff(int a, int b) {
        return abs(getx(a) - getx(b)) + abs(gety(a) - gety(b));
    }
    
    int getx(int c) { return c % COLS; }
    int gety(int c) { return c / COLS; }
};

/*
"CAKE"
"HAPPY"
"NEW"
"YEAR"
>> 3
>> 6
>> 3
>> 7
*/
