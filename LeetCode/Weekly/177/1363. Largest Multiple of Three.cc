const int BASE = 10;
const int MAXN = 1e4+5;
const int MOD = 3;
int cnt[BASE];
char S[MAXN];
int N;

class Solution {
public:
    string largestMultipleOfThree(vector<int>& digits) {
        for (int i = 0; i < BASE; ++i) {
            cnt[i] = 0;
        }
        int rem = 0;
        for (int d: digits) {
            ++cnt[d];
            rem = (rem + d) % MOD;
        }
        if (rem == 1) {
            if (!skip1(1)) skip2(2);
        } else if (rem == 2) {
            if (!skip1(2)) skip2(1);
        }
        N = 0;
        for (int i = BASE-1; i >= 0; --i) {
            if (!i && !N && cnt[i]) {
                cnt[i] = 1;
            }
            for (int j = 0; j < cnt[i]; ++j) {
                S[N++] = '0'+i;
            }
        }
        S[N] = '\0';
        return S;
    }

private:
    bool skip1(int d) {
        for (int i = d; i < BASE; i += MOD) {
            if (cnt[i]) {
                --cnt[i];
                return true;
            }
        }
        return false;
    }
    
    void skip2(int d) {
        int amt = 2;
        for (int i = d; i < BASE; i += MOD) {
            while (amt && cnt[i]) {
                --cnt[i];
                --amt;
            }
        }
    }
};
