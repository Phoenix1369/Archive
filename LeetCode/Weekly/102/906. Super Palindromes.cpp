typedef long long lld;
const int LOGN = 20;

class Solution {
public:
    int superpalindromesInRange(string L, string R) {
        lld l = atoll(L.c_str());
        lld r = atoll(R.c_str());
        return solve(r) - solve(l-1);
    }

    int D[LOGN]{ };
    int d=0;

    int P[LOGN]{ };

    bool is_pal(lld k) {
        d = 0;
        while(k) {
            D[d++] = k % 10;
            k /= 10;
        }
        for(int h=0, t=d-1; h < t; ++h, --t) {
            if(D[h] != D[t]) {
                return false;
            }
        }
        return true;
    }

    int solve(lld n) {
        if(!n) return 0;

        for(int i = 0; i < LOGN; ++i) {
            P[i] = 0;
        }

        // Iterate on palindromes up to 10^9
        int ret = 0;
        int len = 1;
        int lenh = 0;

        int cur = 0;
        while(true) {
            while(++P[cur] == 10) {
                if(!cur) {
                    // Increase length
                    P[0] = 1;
                    if(++len & 1) {
                        ++lenh;
                    }
                    break;
                } else {
                    P[cur] = 0;
                    --cur;
                }
            }
            // Recover palindrome
            lld num = 0LL;
            for(int i = 0; i <= lenh; ++i) {
                num = num*10LL + P[i];
            }
            for(int i = lenh-(len&1); i >= 0; --i) {
                num = num*10LL + P[i];
            }

            lld num2 = num*num;
            if((num2 > n) || (num2 < 0))
                break;
            if(is_pal(num2)) ++ret;
            cur = lenh;
        }
        return ret;
    }
};
