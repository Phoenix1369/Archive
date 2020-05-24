const int MAXA = 26;
const string V = "aeiou";

class Solution {
public:
    int maxVowels(string s, int k) {
        int cnt[MAXA]{ };
        int N = s.size();
        int ret = 0;
        for (int i = 0; i < N; ++i) {
            ++cnt[s[i]-'a'];
            if (i >= k) {
                --cnt[s[i-k]-'a'];
            }
            if (i+1 < k) continue;
            int sum = 0;
            for (char c: V) sum += cnt[c-'a'];
            ret = max(sum, ret);
        }
        return ret;
    }
};
