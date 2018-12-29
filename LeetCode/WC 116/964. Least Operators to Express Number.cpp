typedef long long lld;

class Solution {
    int base;
    map<lld,int> dp;
    
    int cost(int p, int step) {
        if (!p)
            return step * 2;
        return step * p;
    }
    
    int dfs(lld n, lld m, int p) {
        if (dp.count(n))
            return dp.at(n);

        lld M = m * base;
        lld rem = n % M;
        
        if (!rem)
            return dfs(n, M, p+1);
        return dp[n] = min(dfs(n - rem, M, p+1) + cost(p, rem / m),
                           dfs(n + M - rem, M, p+1) + cost(p, (M - rem) / m));
    }
    
public:
    int leastOpsExpressTarget(int x, int target) {
        base = x;
        dp.clear();
        dp[0] = 0;
        dp[1] = 2;

        lld end = 1LL*target*x, X = x;
        int cnt = 1;
        while (X <= end) {
            dp[X] = cnt;
            X *= x;
            ++cnt;
        }
        return dfs(target, 1, 0) - 1;
    }
};
