const int MAXN = 5e4+5;
bitset<MAXN> dp;
vector<int> A;
int N;

class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        A = move(arr);
        N = A.size();
        dp.reset();
        return dfs(start);
    }

private:
    bool dfs(int cur) {
        if ((cur < 0) || (cur >= N)) {
            return false;
        }
        if (!A[cur]) {
            return true;
        }
        if (dp[cur]) {
            return false;
        }
        dp.set(cur);
        return
            dfs(cur + A[cur]) ||
            dfs(cur - A[cur]);
    }
};

/*
[4,2,3,0,3,1,2]
5
[4,2,3,0,3,1,2]
0
[3,0,2,1,2]
2
*/
