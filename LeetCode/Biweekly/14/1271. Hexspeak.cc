#define ALL(x) (x).begin(), (x).end()
typedef long long lld;
string D;

class Solution {
public:
    string toHexspeak(string num) {
        formatHex(parseDec(num));
        return valid() ? D : "ERROR";
    }

private:
    char hexchar(int d) {
        if (d >= 10) {
            return 'A' + d - 10;
        } else if (d >= 2) {
            return '0' + d;
        }
        return (d == 1) ? 'I' : 'O';
    }
    
    void formatHex(lld n, const int BASE = 16) {
        D.clear();
        while (n) {
            D.push_back(hexchar(n % BASE));
            n /= BASE;
        }
    }
    
    lld parseDec(string s, const int BASE = 10) {
        lld ret = 0;
        for (char c: s) {
            ret = 1LL * BASE * ret + c - '0';
        }
        return ret;
    }
    
    bool valid() {
        return all_of(ALL(D), [](char c){ return (c >= 'A'); });
    }
};
