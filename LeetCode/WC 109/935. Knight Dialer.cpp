typedef vector<int> vin;

const int MAXN = 10;
const int n = MAXN;
const int MOD = 1e9+7;
const vin moves[MAXN] = {
    {4,6}, {6,8}, {7,9}, {4,8}, {0,3,9},
    {}, {0,1,7}, {2,6}, {1,3}, {2,4}
};
const vector<vin> adj = {
    {0, 0, 0, 0, 1, 0, 1, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 1, 0, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
    {0, 0, 0, 0, 1, 0, 0, 0, 1, 0},
    {1, 0, 0, 1, 0, 0, 0, 0, 0, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 0, 0, 0, 0, 0, 1, 0, 0},
    {0, 0, 1, 0, 0, 0, 1, 0, 0, 0},
    {0, 1, 0, 1, 0, 0, 0, 0, 0, 0},
    {0, 0, 1, 0, 1, 0, 0, 0, 0, 0}
};

class Matrix {
    vector<vin> m;

public:
    Matrix() : Matrix(vector<vin>(n,vin(n, 0))) { }
    Matrix(const vector<vin>& v) : m{v} { }
    
    vin& operator [] (size_t i) { return m[i]; }
    const vin& operator [] (size_t i) const { return m[i]; }
    
    int sum() const {
        int ret = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                ret = (m[i][j] + ret) % MOD;
            }
        }
        return ret;
    }
    void set(int i, int j, int k) { m[i][j] = k; }
};

Matrix operator * (const Matrix& a, const Matrix& b) {
    Matrix c;
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                c[i][j] = (1LL * a[i][k] * b[k][j] % MOD + c[i][j]) % MOD;
            }
        }
    }
    return c;
}

Matrix operator ^ (Matrix b, int e) {
    Matrix r;
    for (int i = 0; i < n; ++i) {
        r.set(i, i, 1);
    }
    while (e) {
        if (e & 1) {
            r = r * b;
        }
        b = b * b;
        e >>= 1;
    }
    return r;
}

class Solution {
    int dp[2][MAXN]{ };

public:
    int knightDialer(int N) {
        if (N == 1) {
            return 10;
        }
        Matrix A{adj};
        A = A ^ (N-1);
        // [1,...,1] * A;
        return A.sum();
    }
};
