#define ALL(x) (x).begin(), (x).end()
const int MAXN = 105;
int dist[MAXN];
vector<int> G[MAXN];
vector<string> V[MAXN];
unordered_map<string,int> seen;
int K, N;

class Solution {
public:
    vector<string> watchedVideosByFriends(
            vector<vector<string>>& watchedVideos,
            vector<vector<int>>& friends,
            int id,
            int level) {
        N = watchedVideos.size();
        K = level;
        init();
        for (int i = 0; i < N; ++i) {
            G[i] = move(friends[i]);
            V[i] = move(watchedVideos[i]);
        }
        bfs(id);
        vector<string> ret;
        for (auto& itr: seen) {
            ret.push_back(itr.first);
        }
        sort(ALL(ret), [&](const string& lhs, const string& rhs) {
            const int lc = seen.at(lhs);
            const int rc = seen.at(rhs);
            return (lc != rc) ? (lc < rc) : (lhs < rhs);
        });
        return ret;
    }

private:
    void bfs(int src) {
        dist[src] = 0;
        queue<int> Q;
        Q.push(src);
        while (!Q.empty()) {
            int cur = Q.front();
            Q.pop();
            for (auto& nxt: G[cur]) {
                if (dist[nxt] != MAXN) continue;
                dist[nxt] = dist[cur] + 1;
                if (dist[nxt] > K) continue;
                Q.push(nxt);
            }
            if (dist[cur] == K) {
                for (auto& vid: V[cur]) {
                    ++seen[vid];
                }
            }
        }
    }
    
    void init() {
        for (int i = 0; i < N; ++i) {
            dist[i] = MAXN;
        }
        seen.clear();
    }
};

/*
[["A","B"],["C"],["B","C"],["D"]]
[[1,2],[0,3],[0,3],[1,2]]
0
1
[["A","B"],["C"],["B","C"],["D"]]
[[1,2],[0,3],[0,3],[1,2]]
0
2
>> ["B","C"]
>> ["D"]
*/
