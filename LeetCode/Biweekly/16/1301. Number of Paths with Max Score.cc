const int MAXN = 105;
const int MOD = 1e9+7;
const int NOPE = -1;
int A[MAXN][MAXN];
int cp[MAXN][MAXN];
int dp[MAXN][MAXN];
int M1, N1;

class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        init(board);
        for (int i = N1; i >= 0; --i) {
            for (int j = M1; j >= 0; --j) {
                if (A[i][j] == NOPE) {
                    dp[i][j] = 0;
                    cp[i][j] = 0;
                    continue;
                }
                if ((i == N1) && (j == M1)) {
                    dp[i][j] = 0;
                    cp[i][j] = 1;
                    continue;
                }
                compute(i, j);
            }
        }
        return {dp[0][0], cp[0][0]};
    }

private:
    void compute(int i, int j) {
        int val = 0;
        int cnt = 0;
        
        bool iN = (i < N1) && (A[i+1][j] != NOPE);
        bool jN = (j < M1) && (A[i][j+1] != NOPE);
        bool ijN = (i < N1) && (j < M1) && (A[i+1][j+1] != NOPE);
        
        if (iN) val = max(dp[i+1][j], val);
        if (jN) val = max(dp[i][j+1], val);
        if (ijN) val = max(dp[i+1][j+1], val);
        
        if (iN && (val == dp[i+1][j])) {
            cnt = (1LL * cp[i+1][j] + cnt) % MOD;
        }
        if (jN && (val == dp[i][j+1])) {
            cnt = (1LL * cp[i][j+1] + cnt) % MOD;
        }
        if (ijN && (val == dp[i+1][j+1])) {
            cnt = (1LL * cp[i+1][j+1] + cnt) % MOD;
        }
        
        if (iN || jN || ijN) {
            val += A[i][j];
        } else {
            A[i][j] = NOPE;
        }
        
        dp[i][j] = val;
        cp[i][j] = cnt;
    }
    
    void init(vector<string>& board) {
        int N = board.size();
        int M = board[0].size();
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                if (board[i][j] == 'X') {
                    A[i][j] = NOPE;
                } else if (board[i][j] <= '9') {
                    A[i][j] = board[i][j] - '0';
                } else {
                    A[i][j] = 0;
                }
            }
        }
        N1 = N-1;
        M1 = M-1;
    }
};

/*
["E23","2X2","12S"]
["E12","1X1","21S"]
["E11","XXX","11S"]
>> [7,1]
>> [4,2]
>> [0,0]
*/
