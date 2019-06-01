const int moves[4][2] = {{0,-1},{+1,0},{0,+1},{-1,0}}; // NESW
const int FREE = 1;
const int SEEN = 2;

class Solution {
    vector<vector<int>>* arr;
    int comp, M, N;
    bool lock;
public:
    int numEnclaves(vector<vector<int>>& A) {
        arr = &A;
        int ret = 0;
        N = A.size();
        M = A[0].size();
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) if (A[i][j] == FREE) {
                comp = 0;
                lock = true;
                dfs(i, j);
                if (lock) {
                    ret += comp;
                }
            }
        }
        return ret;
    }

private:
    void dfs(int row, int col) {
        if ((row < 0) || (row >= N) || (col < 0) || (col >= M)) {
            lock = false;
            return;
        }
        if ((*arr)[row][col] != FREE) return;
        (*arr)[row][col] = SEEN;
        for (int k = 0; k < 4; ++k) {
            int nr = row + moves[k][0];
            int nc = col + moves[k][1];
            dfs(nr, nc);
        }
        ++comp;
    }
};
