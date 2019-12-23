const int MAXA = 26;
unordered_map<char,int> cnt;
unordered_map<string,int> seen;

class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        int N = s.size();
        seen.clear();
        int M = maxSize - minSize + 1;
        seen.reserve(N * M);
        for (int j = minSize; j <= maxSize; ++j) {
            cnt.clear();
            cnt.reserve(MAXA);
            for (int i = 0; i < N; ++i) {
                ++cnt[s[i]-'a'];
                if (i >= j) {
                    int c = s[i-j]-'a';
                    if (!--cnt[c]) {
                        cnt.erase(c);
                    }
                }
                if ((i+1 >= j) && (cnt.size() <= maxLetters)) {
                    ++seen[s.substr(i-j+1, j)];
                }
            }
        }
        int ret = 0;
        for (auto itr: seen) {
            ret = max(itr.second, ret);
        }
        return ret;
    }
};

/*
"aababcaab"
2
3
4
"aaaa"
1
3
3
"aabcabcab"
2
2
3
"abcde"
2
3
3
>> 2
>> 2
>> 3
>> 0
*/
