const unordered_map<char,int> V = {
    {'a', 0}, {'e', 1}, {'i', 2}, {'o', 3}, {'u', 4}
};
const int MAXN = 1<<5;
int head[MAXN];

class Solution {
public:
    int findTheLongestSubstring(string s) {
        int N = s.size();
        for (int i = 0; i < MAXN; ++i) head[i] = N;
        head[0] = -1;
        int best = 0;
        int mask = 0;
        for (int i = 0; i < N; ++i) {
            if (V.count(s[i])) {
                mask ^= (1 << V.at(s[i]));
            }
            if (head[mask] == N) {
                head[mask] = i;
            } else {
                best = max(i - head[mask], best);
            }
        }
        return best;
    }
};
