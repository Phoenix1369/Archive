#define FOR(j, end) for (int j = 0; j < (end); ++j)
typedef long long lld;
const int HASH[2] = {127, 131};
const int MOD = 1e9+7;

class Solution {
    unordered_set<lld> cache;
    string S;
    int N, pos;

public:
    string longestDupSubstring(string S) {
        N = S.size();
        this->S = move(S);
        int lo = 0;
        int hi = N;
        pos = 0;
        while (lo < hi) {
            int mid = (lo + hi + 1) / 2;
            if (f(mid)) {
                lo = mid;
            } else {
                hi = mid-1;
            }
        }
        return this->S.substr(pos, lo);
    }

private:
    bool f(int len) {
        cache.clear();
        cache.reserve(N);
        int power[2] = {1, 1};
        int hash[2] = {0, 0};
        for (int i = 0; i < N; ++i) {
            FOR(j, 2) hash[j] = (1LL * hash[j] * HASH[j] % MOD + S[i]) % MOD;
            if (i >= len) {
                FOR(j, 2) hash[j] = (hash[j] - (1LL * S[i-len] * power[j] % MOD) + MOD) % MOD;
            } else {
                FOR(j, 2) power[j] = 1LL * power[j] * HASH[j] % MOD;
            }
            lld value = (1LL * hash[0]) << 30 | hash[1];
            if (cache.count(value)) {
                pos = i-len+1;
                return true;
            }
            cache.insert(value);
        }
        return false;
    }
};

