const int MAXD = 9;
const int MAXT = 5005;
vector<int> C;
int dp[MAXD][MAXT];
int pd[MAXD][MAXT][2];
char ret[MAXT];
int K, T;

class Solution {
public:
    string largestNumber(vector<int>& cost, int target) {
        C = move(cost);
        T = target;
        init();
        dfs(8, 0);
        recover(8, 0);
        ret[K] = '\0';
        return ret;
    }

private:
    int dfs(int d, int cost) {
        if (cost > T) return 0;
        if (d < 0) {
            return (cost == T) ? 1 : 0;
        }
        if (dp[d][cost] != -1) {
            return dp[d][cost];
        }
        int nc = cost + C[d];
        int lhs = dfs(d, nc);
        if (lhs) ++lhs;
        int rhs = dfs(d-1, cost);
        if (lhs >= rhs) {
            pd[d][cost][0] = d;
            pd[d][cost][1] = nc;
            dp[d][cost] = lhs;
        } else {
            pd[d][cost][0] = d-1;
            pd[d][cost][1] = cost;
            dp[d][cost] = rhs;
        }
        return dp[d][cost];
    }
    
    void recover(int d, int c) {
        K = 0;
        if (!dp[d][c]) {
            ret[K++] = '0';
            return;
        }
        while ((d >= 0) && (c <= T)) {
            int nd = pd[d][c][0];
            int nc = pd[d][c][1];
            if (nd == d) {
                ret[K++] = '1'+d;
            }
            d = nd;
            c = nc;
        }
    }
    
    void init() {
        for (int i = 0; i < MAXD; ++i) {
            for (int j = 0; j <= T; ++j) {
                dp[i][j] = -1;
            }
        }
    }
};
