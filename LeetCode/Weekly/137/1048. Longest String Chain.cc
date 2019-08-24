typedef vector<int> vin;
const int MAXN = 20;
vin buck[MAXN];
vin memo[MAXN];

class Solution {
    vector<string> W;

public:
    int longestStrChain(vector<string>& words) {
        W = move(words);
        int N = W.size();
        for (int i = 0; i < MAXN; ++i) {
            buck[i].clear();
            memo[i].clear();
        }
        for (int i = 0; i < N; ++i) {
            int sz = W[i].size();
            buck[sz].push_back(i);
            memo[sz].push_back(1);
        }
        return solve();
    }

private:
    bool ispre(int a, int b) {
        bool miss = false;
        int i = 0;
        int j = 0;
        while (i < W[a].size()) {
            if (!miss) {
                if (W[a][i] != W[b][j]) {
                    miss = true;
                    ++j;
                }
            }
            if (W[a][i] != W[b][j]) {
                return false;
            }
            ++i;
            ++j;
        }
        return true;
    }
    
    int solve() {
        int ret = 1;
        for (int i = 2; i < MAXN; ++i) {
            for (int j = 0; j < buck[i-1].size(); ++j) {
                for (int k = 0; k < buck[i].size(); ++k) {
                    if (ispre(buck[i-1][j], buck[i][k])) {
                        memo[i][k] = max(memo[i-1][j] + 1, memo[i][k]);
                        ret = max(memo[i][k], ret);
                    }
                }
            }
        }
        return ret;
    }
};
