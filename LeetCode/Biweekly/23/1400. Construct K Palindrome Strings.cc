const int MAXA = 26;

class Solution {
public:
    bool canConstruct(string s, int k) {
        int N = s.size();
        if (N < k) {
            return false;
        }
        int cnt[MAXA]{ };
        for (char c: s) ++cnt[c-'a'];
        int odd = 0;
        for (int i = 0; i < MAXA; ++i) {
            if (cnt[i] & 1) ++odd;
        }
        return (odd <= k);
    }
};
