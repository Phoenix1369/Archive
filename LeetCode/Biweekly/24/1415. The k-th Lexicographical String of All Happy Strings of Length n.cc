const int MAXN = 11;
char S[MAXN];
int K, N;

class Solution {
public:
    string getHappyString(int n, int k) {
        N = n;
        K = k;
        S[N] = '\0';
        dfs(0);
        return S;
    }

private:
    bool dfs(int cur) {
        if (cur == N) {
            --K;
            return (K == 0);
        }
        for (char c = 'a'; c <= 'c'; ++c) {
            if (!cur || (c != S[cur-1])) {
                S[cur] = c;
                if (dfs(cur+1)) {
                    return true;
                }
            }
        }
        S[cur] = '\0';
        return false;
    }
};
