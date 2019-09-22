const int MAXN = 5e4+5;
int pre[MAXN][4];
int suf[MAXN][4];
int cur[4];
int N;

class Solution {
    vector<int> A;

public:
    vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {
        A = move(colors);
        N = A.size();
        prefix();
        suffix();
        return solve(queries);
    }

private:
    void prefix() {
        for (int j = 1; j <= 3; ++j) cur[j] = -MAXN;
        for (int i = 0; i < N; ++i) {
            cur[A[i]] = i;
            for (int j = 1; j <= 3; ++j) {
                pre[i][j] = cur[j];
            }
        }
    }

    void suffix() {
        for (int j = 1; j <= 3; ++j) cur[j] = MAXN* 2;
        for (int i = N-1; i >= 0; --i) {
            cur[A[i]] = i;
            for (int j = 1; j <= 3; ++j) {
                suf[i][j] = cur[j];
            }
        }
    }

    vector<int> solve(vector<vector<int>>& queries) {
        vector<int> ret;
        for (auto& q: queries) {
            int i = q[0]; ++i;
            int c = q[1];

            int res = min(i - pre[i][c], suf[i][c] - i);
            if (res < N) {
                ret.push_back(res);
            } else {
                ret.push_back(-1);
            }
        }
        return ret;
    }
};
