#define CLR(x) memset((x), 0, sizeof(x))
const int MAXN = 7;
int C[MAXN][MAXN]{ };
vector<int> A;
double num;
double sum;
int K, N;

class Solution {
public:
    double getProbability(vector<int>& balls) {
        A = move(balls);
        K = A.size();
        N = 0;
        for (int& a: A) {
            N += a;
        }
        N /= 2;
        init();
        num = 0.0;
        sum = 0.0;
        dfs(0, 0, 0, 0, 1.0);
        return num / sum;
    }

private:
    void dfs(int i, int cnt, int lhs, int rhs, double p) {
        if (i == K) {
            if (cnt != N) return;
            sum += p;
            if (lhs != rhs) return;
            num += p;
            return;
        }
        for (int j = 0; j <= A[i]; ++j) {
            int nl = lhs + (j > 0);
            int nr = rhs + (j < A[i]);
            dfs(i+1, cnt + j, nl, nr, p * C[A[i]][j]);
        }
    }

    void init() {
        CLR(C);
        C[0][0] = 1;
        for (int i = 1; i < MAXN; ++i) {
            C[i][0] = 1;
            for (int j = 1; j <= i; ++j) {
                C[i][j] = C[i-1][j-1] + C[i-1][j];
            }
        }
    }
};
