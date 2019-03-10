const int MAXN = 1005;
std::set<int> in[MAXN];
int out[MAXN]{ };

class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        for (int i = 1; i <= N; ++i) {
            in[i].clear();
            out[i] = 0;
        }
        for (auto tr: trust) {
            // Note a != b
            int a = tr[0];
            int b = tr[1];
            in[b].insert(a);
            ++out[a];
        }
        for (int i = 1; i <= N; ++i) {
            if (!out[i] && ((N-1) == static_cast<int>(in[i].size()))) {
                return i;
            }
        }
        return -1;
    }
};
