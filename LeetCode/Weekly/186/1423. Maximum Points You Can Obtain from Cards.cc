const int MAXN = 1e5+5;
int A[MAXN];
int N;

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        N = cardPoints.size();
        A[0] = 0;
        for (int i = 1; i <= N; ++i) {
            A[i] = A[i-1] + cardPoints[i-1];
        }
        int ret = 0;
        for (int i = 0; i <= k; ++i) {
            int sum = A[N] - A[N-k+i] + A[i];
            ret = max(sum, ret);
        }
        return ret;
    }
};
