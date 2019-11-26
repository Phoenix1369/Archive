#define ALL(x) (x).begin(), (x).end()
const int MAXC = 4;
const string S = "QWER";
unordered_map<char,int> cnt;
int N4;

class Solution {
public:
    int balancedString(string s) {
        int N = s.size();
        N4 = N / MAXC;
        cnt.clear();
        for (char c: s) {
            ++cnt[c];
        }
        if (valid_outer()) {
            return 0;
        }
        int ret = N;
        int head = 0;
        for (int i = 0; i < N; ++i) {
            --cnt[s[i]];
            while ((head <= i) && valid_outer()) {
                ret = min(i + 1 - head, ret);
                ++cnt[s[head]];
                ++head;
            }
        }
        return ret;
    }

private:
    bool valid_outer() {
        return all_of(ALL(S), [&](char c) { return cnt[c] <= N4; });
    }
};

/*
"QWER"
"QQWE"
"QQQW"
"QQQQ"
>> 0
>> 1
>> 2
>> 3
*/
