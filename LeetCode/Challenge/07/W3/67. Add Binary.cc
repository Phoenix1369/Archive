#define ALL(x) (x).begin(), (x).end()
const int MAXC = 1e4+5;
char S[MAXC];

class Solution {
public:
    string addBinary(string a, string b) {
        reverse(ALL(a));
        reverse(ALL(b));
        if (a.size() < b.size()) {
            a += string(b.size() - a.size(), '0');
        } else if (b.size() < a.size()) {
            b += string(a.size() - b.size(), '0');
        }
        int K = a.size();
        int C = 0;
        for (int i = 0; i < K; ++i) {
            int sum = (a[i] - '0') + (b[i] - '0') + C;
            S[i] = (sum & 1) + '0';
            C = (sum >> 1);
        }
        if (C) {
            S[K++] = (C & 1) + '0';
        }
        S[K] = '\0';
        reverse(S, S+K);
        return S;
    }
};
