const int MAXK = 8005;
const int MAXM = 40;

const int HASH = 41;
const int MOD = 1e9+7;
int K, M, N;

vector<vector<int>> A;

struct State {
    int pos[MAXM];
    int sum;
    
    bool operator < (const State& o) const {
        return o.sum < sum;
    }
    
    bool operator == (const State& o) const {
        return equal(pos, pos+M, o.pos, o.pos+M);
    }
};

struct StateHash {
    size_t operator () (const State& s) const {
        size_t hash = 0;
        for (int i = 0; i < N; ++i) {
            hash = (1LL * HASH * hash % MOD + s.pos[i]) % MOD;
        }
        return hash;
    }
};
unordered_set<State, StateHash> seen;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        A = move(mat);
        N = A.size();
        M = A[0].size();
        K = k;
        seen.clear();
        seen.reserve(MAXK);
        State src;
        src.sum = 0;
        for (int i = 0; i < N; ++i) {
            src.pos[i] = 1;
            src.sum += A[i][0];
        }
        return dijkstra(src);
    }

private:
    int dijkstra(const State& src) {
        priority_queue<State> pq;
        pq.push(src);
        for (int i = 1; i < K; ++i) {
            auto cur = pq.top();
            pq.pop();
            for (int i = 0; i < N; ++i) {
                if (cur.pos[i] == M) continue;
                State nxt = cur;
                nxt.sum += A[i][nxt.pos[i]] - A[i][nxt.pos[i] - 1];
                ++nxt.pos[i];
                if (seen.count(nxt)) continue;
                seen.insert(nxt);
                pq.push(nxt);
            }
        }
        return pq.top().sum;
    }
};
