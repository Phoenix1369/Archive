const char ALPH = '`';
const int MAXA = 27;
const int MAXN = 4e5+5;
const int NOPE = -1;

struct SuffixArray {
    // Prefix doubling
    int inv[MAXN], inv2[MAXN];  // Inverse SA
    int  sa[MAXN],  sa2[MAXN];  // Suffix Array
    int pos[MAXN];  // Bucket beginning
    int N, N1;
    string S;

    SuffixArray(string s) {
        S = move(s);
        N = S.size();
        N1 = N + 1;

        init(); // A[0]
        for (int k = 1; k < N; k *= 2) {
            iterate(k);  // A[k]
        }
    }
    
    int at(int i) { return sa[i]; }

private:
    void init() {
        int cnt[MAXA]{ };
        for (int i = 0; i < N; ++i) ++cnt[S[i] - ALPH];
        ++cnt[0];   // End-of-string.

        pos[0] = 0;
        for (int i = 1; i < MAXA; ++i) pos[i] = pos[i-1] + cnt[i-1];
        for (int i = 0; i <= N; ++i) inv[i] = sa[i] = NOPE;

        for (int i = 0; i < N; ++i) {
            int cur = pos[S[i] - ALPH]++;
            sa[cur] = i;
            inv[i] = cur;

            // Inverse bookkeeping.
            if (cur) {
                int prev = sa[cur-1];
                if ((prev != NOPE) && (S[prev] == S[i])) {
                    inv[i] = inv[prev];
                }
            }
        }
        sa[0] = N;
        inv[N] = 0;
    }
    
    void iterate(int k) {
        for (int i = 0; i <= N; ++i) pos[inv[i]] = inv[i];
        for (int i = 0; i <= N; ++i) sa2[i] = NOPE;
        
        for (int i = 0; i <= N; ++i) {
            int p = (sa[i] - k + N1) % N1;
            int cur = pos[inv[p]]++;
            sa2[cur] = p;
            inv2[p] = cur;

            // Inverse bookkeeping.
            if (cur) {
                int prev = sa2[cur-1];
                int u = (prev + k) % N1;
                int v = (p + k) % N1;
                if ((prev != NOPE) &&
                    (inv[prev] == inv[p]) &&
                    (inv[u] == inv[v])) {
                    inv2[p] = inv2[prev];
                }
            }
        }

        // Copy.
        for (int i = 0; i <= N; ++i) {
            sa[i] = sa2[i];
            inv[i] = inv2[i];
        }
    }
};

class Solution {
public:
    string lastSubstring(string s) {
        SuffixArray sa{s};
        return sa.S.substr(sa.at(sa.N));
    }
};
