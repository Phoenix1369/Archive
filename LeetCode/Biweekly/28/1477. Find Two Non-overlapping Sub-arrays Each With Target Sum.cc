const int MAXN = 1e5+5;
int A[MAXN];
int P[MAXN];
int ret, sum;
int N;

class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        N = arr.size();
        for (int i = 1; i <= N; ++i) {
            A[i] = arr[i-1];
        }
        P[0] = MAXN;
        ret = MAXN;
        sum = 0;
        int j = 1;
        for (int i = 1; i <= N; ++i) {
            sum += A[i];
            while (sum > target) {
                sum -= A[j];
                ++j;
            }
            P[i] = P[i-1];
            if (sum == target) {
                int sz = i - j + 1;
                ret = min(P[j-1] + sz, ret);
                P[i] = min(P[i], sz);
            }
        }
        return (ret < MAXN) ? ret : -1;
    }
};
