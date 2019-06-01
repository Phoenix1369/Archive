typedef vector<int> vin;
const int MAXN = 17;
vin buck[MAXN];
vin memo[MAXN];

bool ispre(int a, int b, const vector<string>& words) {
    bool miss = false;
    int i=0, j=0;
    while (i < words[a].size()) {
        if (!miss) {
            if (words[a][i] != words[b][j]) {
                miss = true;
                ++j;
            }
        }
        if (words[a][i] != words[b][j]) {
            return false;
        }
        ++i, ++j;
    }
    return true;
}

class Solution {
public:
    int longestStrChain(vector<string>& words) {
        for (int i = 0; i < MAXN; ++i) {
            buck[i].clear();
            memo[i].clear();
        }
        int N = words.size();
        for (int i = 0; i < N; ++i) {
            int sz = words[i].size();
            buck[sz].push_back(i);
            memo[sz].push_back(1);
        }
        int ret = 1;
        for (int i = 2; i < MAXN; ++i) {
            for (int j = 0; j < buck[i-1].size(); ++j) {
                for (int k = 0; k < buck[i].size(); ++k) {
                    if (ispre(buck[i-1][j], buck[i][k], words)) {
                        memo[i][k] = max(memo[i-1][j] + 1, memo[i][k]);
                        ret = max(memo[i][k], ret);
                    }
                }
            }
        }
        return ret;
    }
};

