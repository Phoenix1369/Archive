template <typename T>
using vec = vector<T>;

const int MAXK = 4;
vec<vec<int>> A;
int M, N;

struct State {
    int cr;             // current (hp)
    int mn;             // minimum (hp)
};
vec<vec<State>> dp;     // valley (max)
vec<vec<State>> hp;     // health (max)

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        A = move(dungeon);
        N = A.size();
        M = A[0].size();
        init();
        for (int i = 1; i < N; ++i) {
            for (int j = 1; j < M; ++j) {
                compute(i, j);
            }
        }
        return 1 - min(dp[N-1][M-1].mn, 0);
    }

private:
    void compute(int i, int j) {
        // Current Health
        int dl = dp[i][j-1].cr + A[i][j];
        int du = dp[i-1][j].cr + A[i][j];
        int hl = hp[i][j-1].cr + A[i][j];
        int hu = hp[i-1][j].cr + A[i][j];
        // Transitions
        State pr[MAXK] = {
            {dl, min(dp[i][j-1].mn, dl)},     // (valley, lf)
            {du, min(dp[i-1][j].mn, du)},     // (valley, up)
            {hl, min(hp[i][j-1].mn, hl)},     // (health, lf)
            {hu, min(hp[i-1][j].mn, hu)},     // (health, up)
        };
        // Maximize minimum health
        dp[i][j] = pr[0];
        for (int k = 1; k < MAXK; ++k) {
            if  ((pr[k].mn >  dp[i][j].mn) ||
                ((pr[k].mn == dp[i][j].mn) && (pr[k].cr > dp[i][j].cr))) {
                dp[i][j] = pr[k];
            }
        }
        // Maximize current health
        hp[i][j] = pr[0];
        for (int k = 1; k < MAXK; ++k) {
            if  ((pr[k].cr >  hp[i][j].cr) ||
                ((pr[k].cr == hp[i][j].cr) && (pr[k].mn > hp[i][j].mn))) {
                hp[i][j] = pr[k];
            }
        }
    }

    void init() {
        // Init
        dp.assign(N, vec<State>(M, {0, 0}));
        hp.assign(N, vec<State>(M, {0, 0}));
        // Base
        dp[0][0] = {A[0][0], A[0][0]};
        hp[0][0] = dp[0][0];
        // Fill
        for (int j = 1; j < M; ++j) {
            dp[0][j].cr = dp[0][j-1].cr + A[0][j];
            dp[0][j].mn = min(dp[0][j-1].mn, dp[0][j].cr);
            hp[0][j] = dp[0][j];
        }
        for (int i = 1; i < N; ++i) {
            dp[i][0].cr = dp[i-1][0].cr + A[i][0];
            dp[i][0].mn = min(dp[i-1][0].mn, dp[i][0].cr);
            hp[i][0] = dp[i][0];
        }
    }
};
