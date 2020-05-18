const int MAXN = 1e4+5;
unordered_map<string, string> up;

class Solution {
public:
    string findSmallestRegion(
            vector<vector<string>>& regions,
            string r1,
            string r2
    ) {
        init();
        for (auto reg: regions) {
            int M = reg.size();
            for (int i = 1; i < M; ++i) {
                up[reg[i]] = reg[0];
            }
        }
        int la = level(r1);
        int lb = level(r2);
        for (; la > lb; --la) r1 = up[r1];
        for (; lb > la; --lb) r2 = up[r2];
        while (r1 != r2) {
            r1 = up[r1];
            r2 = up[r2];
        }
        return r1;
    }

private:
    void init() {
        up.clear();
        up.reserve(MAXN);
    }
    
    int level(string s) {
        int lvl = 0;
        while (up.count(s)) {
            s = up[s];
            ++lvl;
        }
        return lvl;
    }
};
