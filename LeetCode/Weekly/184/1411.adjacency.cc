template <typename T>
using vec = vector<T>;

const int MOD = 1e9+7;
const vec<vec<int>> G = {
    {0,0,0,0, 1,1,0,1, 1,1,0,0},
    {0,0,0,0, 1,0,1,1, 1,0,0,0},
    {0,0,0,0, 1,1,0,0, 1,1,0,1},
    {0,0,0,0, 0,1,0,0, 0,1,1,1},
    
    {1,1,1,0, 0,0,0,0, 0,0,1,1},
    {1,0,1,1, 0,0,0,0, 0,0,1,0},
    {0,1,0,0, 0,0,0,0, 1,1,0,1},
    {1,1,0,0, 0,0,0,0, 0,1,1,1},
    
    {1,1,1,0, 0,0,1,0, 0,0,0,0},
    {1,0,1,1, 0,0,1,1, 0,0,0,0},
    {0,0,0,1, 1,1,0,1, 0,0,0,0},
    {0,0,1,1, 1,0,1,1, 0,0,0,0},
};

class Matrix {
    vec<vec<int>> M;

public:
    Matrix(const vec<vec<int>>& M) : M{M} { }
    
    Matrix& operator *= (const Matrix& o) {
        int N = M.size();
        vec<vec<int>> ret(N, vec<int>(N, 0));
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                for (int k = 0; k < N; ++k) {
                    int val = 1LL * M[i][k] * o.M[k][j] % MOD;
                    ret[i][j] = (ret[i][j] + val) % MOD;
                }
            }
        }
        M = move(ret);
        return *this;
    }
    
    void identity() {
        int N = M.size();
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                M[i][j] = (i == j) ? 1 : 0;
            }
        }
    }
    
    Matrix& pow(int e) {
        Matrix B = *this;
        Matrix R = B;
        R.identity();
        while (e) {
            if (e & 1) {
                R *= B;
            }
            B *= B;
            e /= 2;
        }
        M = move(R.M);
        return *this;
    }
    
    int sum() const {
        int sum = 0;
        for (const auto& row: M) {
            for (int x: row) {
                sum = (sum + x) % MOD;
            }
        }
        return sum;
    }
};

class Solution {
public:
    int numOfWays(int n) {
        Matrix A{G};
        return A.pow(n-1).sum();
    }
};
