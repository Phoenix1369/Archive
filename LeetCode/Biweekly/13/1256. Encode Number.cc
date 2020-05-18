const int MAXS = 32;
char S[MAXS];

class Solution {
public:
    string encode(int num) {
        int K = 0;
        int two = 0;
        while (num > 0) {
            num -= (1 << two);
            if (num < 0) {
                break;
            }
            S[K++] = '0' + ((num >> two) & 1);
            ++two;
        }
        S[K] = '\0';
        reverse(S, S+K);
        return S;
    }
};
