const int MAXN = 505;
const int NOPE = -1;
int P[MAXN];
int M, N;

class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
        N = mat.size();
        M = mat[0].size();
        for (int i = 0; i < N; ++i) P[i] = 0;
        
        int best = 0;
        int rows = 0;
        for (int k = 0; k < M; ++k) {
            for (int i = 0; i < N; ++i) {
                while ((P[i] < M) && (mat[i][P[i]] < mat[best][P[best]])) ++P[i];
                if (P[i] >= M) {
                    return NOPE;
                } else if (mat[i][P[i]] > mat[best][P[best]]) {
                    best = i;
                    rows = 1;
                } else {
                    if (rows == N) {
                        return mat[best][P[best]];
                    }
                    ++rows;
                }
            }
        }
        return NOPE;
    }
};
