#define ALL(x) (x).begin(), (x).end()
vector<string> ret;
string S, T;
int N;

class Solution {
public:
    vector<string> permute(string s) {
        ret.clear();
        S = move(s);
        N = S.size();
        T.clear();
        dfs(0);
        sort(ALL(ret));
        return ret;
    }

private:
    void dfs(int pos) {
        if (pos == N) {
            ret.push_back(T);
            return;
        }
        if (S[pos] != '{') {
            T.push_back(S[pos]);
            dfs(pos + 1);
            T.pop_back();
            return;
        }
        int cur = pos + 1;
        int end = pos;
        while (S[end] != '}') end += 2;
        while (cur < end) {
            T.push_back(S[cur]);
            dfs(end + 1);
            T.pop_back();
            cur += 2;
        }
    }
};
