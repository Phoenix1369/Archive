bool is_IPv4;

struct State {
    int B, K, L, N;
    int (*f)(int);
    char D;
};

class Solution {
public:
    string validIPAddress(string IP) {
        is_IPv4 = (IP.find('.') != string::npos);
        bool ret = is_IPv4
            ? tryIP(IP, {10, 3, 4, 255, isdigit, '.'})
            : tryIP(IP, {16, 7, 4, -1, isxdigit, ':'});
        return ret
            ? (is_IPv4 ? "IPv4" : "IPv6")
            : "Neither";
    }

private:
    bool tryIP(string ip, const State& s) {
        int cnt = 0;
        int len = 0;
        int sum = 0;
        for (char c: ip) {
            if (c == s.D) {
                if (!len) {
                    return false;   // empty group
                }
                if (++cnt > s.K) {
                    return false;   // extra group
                }
                len = 0;
                sum = 0;
            } else if (s.f(c)) {
                if (is_IPv4 && len && !sum) {
                    return false;   // leading zero
                }
                ++len;
                if (len > s.L) {
                    return false;   // exceed size
                }
                sum = sum * s.B + stoi(string(1, c), nullptr, s.B);
                if (is_IPv4 && (sum > s.N)) {
                    return false;   // exceed value
                }
            } else {
                return false;       // invalid char
            }
        }
        if (!len) {
            return false;   // empty group
        }
        if (cnt < s.K) {
            return false;   // missing group
        }
        return true;
    }
};
