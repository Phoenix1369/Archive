typedef long long lld;

class Solution {
    vector<int> A;
    int M, N;

public:
    vector<double> sampleStats(vector<int>& count) {
        A = move(count);
        N = A.size();
        M = 0;
        // Summary Statistics
        int maxx = 0;
        int minn = -1;
        int mode = 0;
        lld sum = 0LL;
        for (int i = 0; i < N; ++i) {
            if (A[i]) maxx = i;
            if (A[i] && (minn == -1)) minn = i;
            if (A[i] > A[mode]) mode = i;
            sum += i * A[i];
            M += A[i];
        }
        return { minn, maxx, 1.0 * sum / M, find_median(), mode };
    }

private:
    double find_median() {
        int sum = 0;
        int half = (M + 1) / 2;
        for (int i = 0; i < N; ++i) {
            sum += A[i];
            if (M & 1) {
                if (sum >= half) {
                    return i;
                }
                continue;
            }
            // (M & 1) == 0
            if (sum < half) {
                continue;
            }
            if (sum > half) {
                return i;
            }
            // (sum == half)
            for (int j = i + 1; j < N; ++j) {
                if (A[j]) {
                    return (i + j) / 2.0;
                }
            }
        }
        exit(-1);
    }
};
