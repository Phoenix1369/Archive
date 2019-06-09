#define ALL(x) (x).begin(), (x).end()
const int MAXN = 8;
int F[MAXN];

class Solution {
    vector<int> pos;
    string S;
    int N, sum, ret;

public:
    int numTilePossibilities(string tiles) {
        sort(ALL(tiles));
        S = move(tiles);
        N = S.size();

        F[0] = 1;
        for (int i = 1; i < MAXN; ++i) {
            F[i] = F[i-1] * i;
        }

        ret = sum = 0;
        dfs(0);
        return --ret;
    }

private:
    void dfs(int cur) {
        if (cur == N) {
            int val = F[sum];
            for (auto p: pos) {
                val /= F[p];
            }
            ret += val;
            return;
        }

        int nxt = cur;
        while ((nxt < N) && (S[nxt] == S[cur])) ++nxt;

        for (int i = nxt-cur; i >= 0; --i) {
            pos.push_back(i);
            sum += i;
            dfs(nxt);
            sum -= i;
            pos.pop_back();
        }
    }
};
