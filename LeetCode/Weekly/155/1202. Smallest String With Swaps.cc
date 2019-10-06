#define ALL(x) (x).begin(), (x).end()
const int MAXN = 1e5+5;
int color[MAXN]{ };
vector<int> G[MAXN];
vector<char> L[MAXN];
int pos[MAXN];
int C, M, N;
string S;

class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        S = move(s);
        N = S.size();
        M = pairs.size();
        init();
        for (int i = 0; i < M; ++i) {
            int u = pairs[i][0];
            int v = pairs[i][1];
            G[u].push_back(v);
            G[v].push_back(u);
        }
        C = 0;
        for (int i = 0; i < N; ++i) {
            if (color[i]) continue;
            color[i] = ++C;
            dfs(i);
        }
        for (int i = 1; i <= C; ++i) {
            sort(ALL(L[i]));
        }
        string ret;
        for (int i = 0; i < N; ++i) {
            int c = color[i];
            ret.push_back(L[c][pos[c]++]);
        }
        return ret;
    }
    
private:
    void dfs(int cur) {
        L[color[cur]].push_back(S[cur]);
        for (auto nxt: G[cur]) {
            if (color[nxt]) continue;
            color[nxt] = color[cur];
            dfs(nxt);
        }
    }
    
    void init() {
        for (int i = 0; i < N; ++i) {
            color[i] = 0;
            G[i].clear();
            L[i].clear();
            pos[i] = 0;
        }
    }
};
