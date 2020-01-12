#define ALL(x) (x).begin(), (x).end()
const int BASE = 10;

class Solution {
public:
    string freqAlphabets(string s) {
        int N = s.size();
        string ret;
        for (int i = N-1; i >= 0; --i) {
            if (s[i] == '#') {
                int val = (s[i-2] - '0') * BASE + (s[i-1] - '0');
                ret.push_back(get(val));
                i -= 2;
            } else {
                ret.push_back(get(s[i] - '0'));
            }
        }
        reverse(ALL(ret));
        return ret;
    }

private:
    char get(int x) {
        return 'a' + (x - 1);
    }
};
