const unordered_map<string, char> D = {
    {"&quot;", '"'}, {"&apos;", '\''}, {"&amp;", '&'},
    {"&gt;", '>'}, {"&lt;", '<'}, {"&frasl;", '/'}
};
const int MAXN = 1e5+5;
char S[MAXN];
int M, N;

class Solution {
public:
    string entityParser(string text) {
        N = text.size();
        M = 0;
        for (int i = 0; i < N; ++i) {
            bool match = false;
            for (auto itr: D) {
                int K = itr.first.size();
                if (text.compare(i, K, itr.first) == 0) {
                    S[M++] = itr.second;
                    match = true;
                    i += K-1;
                    break;
                }
            }
            if (!match) S[M++] = text[i];
        }
        S[M] = '\0';
        return S;
    }
};
