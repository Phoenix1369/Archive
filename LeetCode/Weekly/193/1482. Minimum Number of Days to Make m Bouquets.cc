const int MAXB = 1e9;
vector<int> B;
int K, M, N;

class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        B = move(bloomDay);
        N = B.size();
        M = m;
        K = k;
        int lo = 1;
        int hi = MAXB + 1;
        while (lo < hi) {
            int x = (1LL * lo + hi) / 2;
            if (f(x) >= M) {
                hi = x;
            } else {
                lo = x+1;
            }
        }
        return (lo <= MAXB) ? lo : -1;
    }

private:
    int f(int x) {
        int cnt = 0;
        int sum = 0;
        for (int i = 0; i < N; ++i) {
            if (B[i] > x) {
                cnt += sum / K;
                sum = 0;
            } else {
                ++sum;
            }
        }
        cnt += sum / K;
        return cnt;
    }
};
