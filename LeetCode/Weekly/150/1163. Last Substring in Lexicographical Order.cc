const int MAXN = 4e5+5;
bool live[MAXN]{ };

class Solution {
public:
    string lastSubstring(string s) {
        int N = s.size();
        
        vector<int> good;
        good.reserve(N);
        for (int i = 0; i < N; ++i) {
            good.push_back(i);
            live[i] = true;
        }
        
        vector<int> succ;
        for (int k = 0; good.size() > 1u; ++k) {
            char Z = 'a';
            for (auto p: good) {
                if (p + k >= N) continue;
                Z = max(s[p + k], Z);
                if (!k) continue;
                if (live[p + k]) {
                    live[p + k] = false;
                }
            }
            for (auto p: good) {
                if ((p + k >= N) || (s[p + k] != Z)) live[p] = false;
                if (live[p]) succ.push_back(p);
            }
            good = move(succ);
        }
        return s.substr(good[0]);
    }
};
