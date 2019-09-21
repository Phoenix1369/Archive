typedef pair<int,int> pii;
const int LAX = 5;
const int MAXK = 8;
const int NOPE = -1;
const pii moves[MAXK] = {
    {-2,1}, {-1,2}, {1,2}, {2, 1},
    {2,-1}, {1,-2}, {-1,-2}, {-2,-1}
};
map<pii,int> memo;

// Prune loosely by Manhattan distance, similar to A*

class Solution {
public:
    int minKnightMoves(int x, int y) {
        memo.clear();
        
        pii src = {0, 0};
        pii snk = {x, y};
        int best = dist(src, snk);
        
        queue<pii> Q;
        memo[src] = 0;
        Q.emplace(src);
        while (!Q.empty()) {
            pii cur = Q.front();
            Q.pop();
            if (cur == snk) {
                return memo.at(cur);
            }
            for (int k = 0; k < MAXK; ++k) {
                pii nxt = {
                    cur.first + moves[k].first,
                    cur.second + moves[k].second
                };
                if (memo.count(nxt)) continue;
                
                int md = dist(nxt, snk);
                if (md >= best + LAX) continue;
                if (md < best) best = md;
                
                memo[nxt] = memo.at(cur) + 1;
                Q.push(nxt);
            }
        }
        return NOPE;
    }
    
private:
    int dist(const pii& A, const pii& B) {
        return abs(A.first - B.first) + abs(A.second - B.second);
    }
};
