#define ALL(x) (x).begin(), (x).end()
typedef vector<int> vin;
const int MAXN = 1e4+5;
int C[MAXN]; // colour

class Solution {
public:
    int minimumCost(int N, vector<vector<int>>& connections) {
        iota(C+1, C+N+1, 1);
        sort(ALL(connections), [](const vin& lhs, const vin& rhs) {
            return lhs[2] < rhs[2];
        });
        int ret = 0;
        for (auto e: connections) {
            if (found(e[0]) != found(e[1])) {
                unite(e[0], e[1]);
                ret += e[2];
            }
        }
        for (int i = 1; i <= N; ++i) {
            if (found(i) != found(1)) {
                return -1;
            }
        }
        return ret;
    }

private:
    int found(int p) {
        int q = p;
        while (q != C[q]) {
            q = C[q];
        }
        int tmp;
        while (p != C[p]) {
            tmp = C[p];
            C[p] = q;
            p = tmp;
        }
        return p;
    }

    void unite(int a, int b) {
        a = found(a);
        b = found(b);
        C[a] = b;
    }
};
