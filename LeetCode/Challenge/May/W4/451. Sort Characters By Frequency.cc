#define ALL(x) (x).begin(), (x).end()
const int MAXA = 128;

class Solution {
public:
    string frequencySort(string s) {
        int cnt[MAXA]{ };
        for (char c: s) ++cnt[c];
        sort(ALL(s), [&cnt](char a, int b) {
            return (cnt[a] != cnt[b]) ? (cnt[a] > cnt[b]) : (a > b);
        });
        return s;
    }
};
