const int MAXS = 1e4+5;
char S[MAXS];
char T[MAXS];

class Solution {
public:
    string removeKdigits(string num, int K) {
        // Inversions
        int N = num.size();
        int M = 0;
        for (int i = 0; i < N; ) {
            if (K && M && (S[M-1] > num[i])) {
                --M;
                --K;
            } else {
                S[M++] = num[i++];
            }
        }
        S[M] = '\0';
        
        // Maximum
        for (char c = '9'; (c >= '0') && K; --c) {
            int N = 0;
            for (int i = 0; i < M; ++i) {
                if ((S[i] != c) || !K) {
                    T[N++] = S[i];
                } else {
                    --K;
                }
            }
            T[N] = '\0';
            strcpy(S, T);
        }
        
        // Leading Zeroes
        char *ptr = S;
        while (*ptr == '0') ++ptr;
        return *ptr ? ptr : "0";
    }
};
