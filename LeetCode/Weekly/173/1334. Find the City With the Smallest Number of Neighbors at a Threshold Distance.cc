const int INFN = 1e7+5;
const int MAXN = 105;
int A[MAXN][MAXN];
int D[MAXN];

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                A[i][j] = (i == j) ? 0 : INFN;
            }
        }
        for (auto& e: edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];
            A[u][v] = A[v][u] = w;
        }
        
        floyd_warshall(n);
        
        int ret = 0;
        for (int i = 0; i < n; ++i) {
            D[i] = 0;
            for (int j = 0; j < n; ++j) {
                if (A[i][j] <= distanceThreshold) {
                    ++D[i];
                }
            }
            if (D[i] <= D[ret]) {
                ret = i;
            }
        }
        return ret;
    }

private:
    void floyd_warshall(int n) {
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    A[i][j] = min(A[i][k] + A[k][j], A[i][j]);
                }
            }
        }
    }
};
