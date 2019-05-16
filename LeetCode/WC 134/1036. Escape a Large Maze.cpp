#define ALL(x) (x).begin(), (x).end()
typedef long long lld;
typedef vector<int> vin;
const int MAXN = 1e6;
const int MAXL = 2e4+5;
unordered_set<lld> nope;
unordered_set<lld> seen;
lld Q[MAXL];

class Solution {
    int moves[4][2] = {{0,-1},{+1,0},{0,+1},{-1,0}};
    int qh, qt;

public:
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        nope.clear();
        nope.reserve(blocked.size());
        for (const vin& b: blocked) {
            nope.insert(coord(b));
        }
        lld src = coord(source);
        lld snk = coord(target);
        return bound_bfs(src, snk) && bound_bfs(snk, src);
    }

private:
    bool bound_bfs(const lld& src, const lld& snk) {
        seen.clear();
        seen.reserve(MAXL);
        seen.insert(src);

        qh = qt = 0;
        Q[qt++] = src;
        while (qh < qt) {
            lld cur = Q[qh++];
            if (cur == snk) {
                return true;
            }
            for (int k = 0; k < 4; ++k) {
                int nx = cur / MAXN + moves[k][0];
                int ny = cur % MAXN + moves[k][1];
                lld nxt = coord({nx, ny});
                if ((0 <= nx) && (nx < MAXN) &&
                    (0 <= ny) && (ny < MAXN) &&
                    !nope.count(nxt) && !seen.count(nxt)) {
                    seen.insert(nxt);
                    Q[qt++] = nxt;
                    if (qt >= MAXL) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

private:
    lld coord(const vin& pos) {
        return 1LL * pos[0] * MAXN + pos[1];
    }
};

