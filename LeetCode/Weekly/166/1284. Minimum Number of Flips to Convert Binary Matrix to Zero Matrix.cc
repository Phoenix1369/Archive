const int MAXK = 1<<9;
const int NOPE = -1;
const int moves[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
int dist[MAXK];
int M, N;

class Solution {
public:
    int minFlips(vector<vector<int>>& mat) {
        N = mat.size();
        M = mat[0].size();
        init();
        int src = extract(mat);
        queue<int> Q;
        Q.push(src);
        dist[src] = 0;
        while (!Q.empty()) {
            int cur = Q.front();
            Q.pop();
            if (cur == 0) {
                return dist[cur];
            }
            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < M; ++j) {
                    int nxt = flip(cur, i, j);
                    if (dist[nxt] == NOPE) {
                        Q.push(nxt);
                        dist[nxt] = dist[cur] + 1;
                    } 
                }
            }
        }
        return NOPE;
    }

private:
    int extract(vector<vector<int>>& mat) {
        int val = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                val = (val << 1) | mat[i][j];
            }
        }
        return val;
    }
    
    int flip(int cur, int y, int x) {
        vector<vector<int>> A(3, vector<int>(3, 0));
        for (int i = N-1; i >= 0; --i) {
            for (int j = M-1; j >= 0; --j) {
                A[i][j] = (cur & 1);
                cur >>= 1;
            }
        }
        A[y][x] ^= 1;
        for (int k = 0; k < 4; ++k) {
            int ny = y + moves[k][0];
            int nx = x + moves[k][1];
            if ((0 <= ny) && (ny < N) && (0 <= nx) && (nx < M)) {
                A[ny][nx] ^= 1;
            }
        }
        return extract(A);
    }
    
    void init() {
        for (int i = 0; i < MAXK; ++i) {
            dist[i] = NOPE;
        }
    }
};

/*
[[0,0],[0,1]]
[[0]]
[[1,1,1],[1,0,1],[0,0,0]]
[[1,0,0],[1,0,0]]
>> 3
>> 0
>> 6
>> -1
*/
