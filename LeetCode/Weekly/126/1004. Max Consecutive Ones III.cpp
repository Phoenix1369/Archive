class Solution {
    vector<int> A;
    int K, N;
public:
    int longestOnes(vector<int>& A, int K) {
        this->A = A;
        this->K = K;
        this->N = this->A.size();
        int lo = 0, hi = N;
        while (lo < hi) {
            int x = (lo + hi + 1) / 2;
            if (f(x)) {
                lo = x;
            } else {
                hi = x-1;
            }
        }
        return lo;
    }

private:
    bool f(int X) {
        int cnt[2]{ };
        for (int i = 0; i < X; ++i) {
            ++cnt[A[i]];
        }
        for (int i = X; i < N; ++i) {
            if (cnt[0] <= K) {
                return true;
            }
            --cnt[A[i-X]];
            ++cnt[A[i]];
        }
        return (cnt[0] <= K);
    }
};