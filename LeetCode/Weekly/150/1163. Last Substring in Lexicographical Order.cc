const int MAXN = 4e5+5;
bool live[MAXN];

class Solution {
public:
    string lastSubstring(string s) {
        char Z = 'a';
        for (char c: s) Z = max(c, Z);

        int N = s.size();
        vector<int> good;
        for (int i = 0; i < N; ++i) live[i] = false;
        for (int i = 0; i < N; ++i) {
            if (s[i] != Z) continue;
            good.push_back(i);
            live[i] = true;
        }

        vector<int> succ;
        for (int k = 1; good.size() > 1u; ++k) {
            Z = 'a';
            for (auto p: good) {
                if (p + k >= N) {
                    live[p] = false;
                    continue;
                }
                if (live[p + k]) {
                    live[p + k] = false;
                }
                Z = max(s[p + k], Z);
            }
            for (auto p: good) {
                if (s[p + k] != Z) live[p] = false;
                if (live[p]) succ.push_back(p);
            }
            good = move(succ);
        }
        return s.substr(good[0]);
    }
};
