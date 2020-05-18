const int MAXA = 26;

class Solution {
public:
    int numKLenSubstrNoRepeats(string S, int K) {
        int N = S.size();
        int cnt[MAXA]{ };
        int ret = 0;
        for (int i = 0; i < N; ++i) {
            ++cnt[S[i]-'a'];
            if (i+1 < K) continue;
            if (i  >= K) --cnt[S[i-K]-'a'];
            bool valid = all_of(cnt, cnt + MAXA,
                [](int c){ return (c <= 1); }
            );
            if (valid) ++ret;
        }
        return ret;
    }
};
