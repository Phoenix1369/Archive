enum Chair { BLOCKED, BROKEN, EMPTY, TAKEN };

const int MAXN = 8;
Chair A[MAXN][MAXN];
int B[MAXN][MAXN];
int cnt, ret;
int M, N;

class Solution {
public:
    int maxStudents(vector<vector<char>>& seats) {
        N = seats.size();
        M = seats[0].size();
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                A[i][j] = (seats[i][j] == '.') ? EMPTY : BROKEN;
                B[i][j] = 0;
            }
        }
        cnt = 0;
        ret = 0;
        dfs(N-1, 0);
        return ret;
    }

private:
    void dfs(int row, int col) {
        if (row == -1) {
            ret = max(cnt, ret);
            return;
        }
        int rem = (M * row + (M - col) + 1) / 2 + 1;
        if (cnt + rem <= ret) {
            return;
        }
        
        int cr = col+1;
        int nc = (cr < M) ? cr : 0;
        int nr = (cr < M) ? row : (row-1);
        if (A[row][col] == EMPTY) {
            place(row, col, false);
            ++cnt;
            dfs(nr, nc);
            --cnt;
            place(row, col, true);
        }
        dfs(nr, nc);
    }
    
    void place(int row, int col, bool reset) {
        A[row][col] = (reset) ? EMPTY : TAKEN;
        
        for (int dr = -1; dr <= 0; ++dr) {
            for (int dc = -1; dc <= 1; dc += 2) {
                int nr = row + dr;
                int nc = col + dc;
                if ((nr < 0) || (nr >= N) || (nc < 0) || (nc >= M)) {
                    continue;
                }
                
                if (reset) {
                    if (A[nr][nc] == BLOCKED) {
                        if (--B[nr][nc] == 0) {
                            A[nr][nc] = EMPTY;
                        }
                    }
                } else {
                    if (A[nr][nc] == EMPTY) {
                        A[nr][nc] = BLOCKED;
                    }
                    if (A[nr][nc] == BLOCKED) {
                        ++B[nr][nc];
                    }
                }
            }
        }
    }
};
