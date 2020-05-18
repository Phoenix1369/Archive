#define ALL(x) (x).begin(), (x).end()
vector<int> A;
int K, N;

class Solution {
public:
    int maximizeSweetness(vector<int>& sweetness, int k) {
        A = move(sweetness);
        N = A.size();
        K = ++k;
        int lo = 0;
        int hi = accumulate(ALL(A), 0);
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
    bool f(int x) {
        int cnt = 0;
        int sum = 0;
        for (int i = 0; i < N; ++i) {
            sum += A[i];
            if (sum >= x) {
                ++cnt;
                sum = 0;
            }
        }
        if (sum >= x) ++cnt;
        return (cnt >= K);
    }
};
