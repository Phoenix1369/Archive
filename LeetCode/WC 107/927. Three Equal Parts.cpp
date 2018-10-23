const int HASH = 999000911;
const int MAXN = 3e4+5;
const int MOD = 1e9+7;
map<int,int> pos;
int H[MAXN]{ };
int M[MAXN]{ };

class Solution {
public:
    vector<int> threeEqualParts(vector<int>& A) {
        int n = (int)A.size();
        H[0] = 0;
        M[0] = 1;
        for (int i = 1; i <= n; ++i) {
            H[i] = (1LL*H[i-1]*HASH % MOD + A[i-1]) % MOD;
            M[i] = (1LL*M[i-1]*HASH)% MOD;
        }
        pos.clear();
        for (int i = n; i >= 1; --i) {
            pos[H[i]] = i;
        }
        for (int i = n; i >= 1; --i) {
            int cur = (H[n] - (1LL*H[i-1]*M[n-i+1] % MOD) + MOD) % MOD;
            if (!pos.count(cur)) {
                continue;
            }
            int j = pos.at(cur);
            if (j >= (i-1)) {
                continue;
            }
            int mid = (H[i-1] - (1LL*H[j]*M[i-j-1] % MOD) + MOD) % MOD;
            if (cur == mid) {
                return { j-1, i-1 };
            }
        }
        return {-1,-1};
    }
};
