class Solution {
    const vector<int> base = {0,1,2,6};
public:
    int clumsy(int N) {
        return dfs(N, +1);
    }

private:
    int dfs(int N, int mul = -1) {
        if (N <= 3) {
            return 1LL*(mul)*base[N];
        }
        return 1LL*(mul)*N*(N-1)/(N-2) + dfs2(N-3);
    }
    int dfs2(int N) {
        if (N == 1) {
            return 1;
        }
        return N + dfs(N-1);
    }
};
