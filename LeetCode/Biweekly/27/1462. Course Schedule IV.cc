const int MAXN = 105;
int A[MAXN][MAXN];
int N;

class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        N = n;
        init();
        for (auto& e: prerequisites) {
            A[e[0]][e[1]] = true;
        }
        floyd_warshall();
        vector<bool> ret;
        for (auto& q: queries) {
            ret.push_back(A[q[0]][q[1]]);
        }
        return ret;
    }

private:
    void floyd_warshall() {
        for (int k = 0; k < N; ++k) {
            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < N; ++j) {
                    A[i][j] |= A[i][k] & A[k][j];
                }
            }
        }
    }
    
    void init() {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                A[i][j] = false;
            }
        }
    }
};
