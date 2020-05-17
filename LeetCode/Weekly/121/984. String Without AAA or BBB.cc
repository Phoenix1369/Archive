const int MAXN = 205;
char S[MAXN];

class Solution {
public:
    string strWithout3a3b(int A, int B) {
        int N = 0;
        bool flip = (A < B);
        int cnt[2] = {A, B};
        int pad[2] = {max(A - B, 0), max(B - A, 0)};
        char chr[2] = {'a', 'b'};
        for (int i = 0; (cnt[0] || cnt[1]); i ^= 1) {
            int turn = i ^ flip;
            if (cnt[turn]) {
                S[N++] = chr[turn];
                --cnt[turn];
            }
            if (cnt[turn] && pad[turn]) {
                S[N++] = chr[turn];
                --cnt[turn];
                --pad[turn];
            }
        }
        S[N] = '\0';
        return S;
    }
};
