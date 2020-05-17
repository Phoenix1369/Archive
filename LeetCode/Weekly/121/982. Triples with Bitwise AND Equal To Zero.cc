#define CLR(x) memset(dp, -1, sizeof(dp))
const int MAXA = 1<<16;
const int MAXK = 3;
int dp[MAXK][MAXA];
vector<int> A;
int N;

class Solution {
public:
    int countTriplets(vector<int>& arr) {
        A = move(arr);
        N = A.size();
        CLR(dp);
        return dfs(0, MAXA-1);
    }

private:
    int dfs(int cnt, int mask) {
        if (cnt == 3) {
            return (mask == 0) ? 1 : 0;
        }
        if (dp[cnt][mask] != -1) {
            return dp[cnt][mask];
        }
        int ret = 0;
        for (int i = 0; i < N; ++i) {
            ret += dfs(cnt+1, mask & A[i]);
        }
        return dp[cnt][mask] = ret;
    }
};
