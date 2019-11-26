#define ALL(x) (x).begin(), (x).end()
typedef long long lld;
template <typename T>
using vec = vector<T>;

const int MAXN = 13;
map<lld, int> seen;
int M, N;
int best;

class Solution {
public:
    int tilingRectangle(int n, int m) {
        M = m;
        N = n;
        best = M * N;
        seen.clear();
        
        vec<int> src(n, 0);
        dfs(src, 0);
        return best;
    }

private:
    void dfs(vec<int>& cur, int moves) {
        if (moves >= best) {
            return;
        }
        int val = *min_element(ALL(cur));
        if (val == M) {
            best = moves;
            return;
        }
        lld hash = get(cur);
        if (seen.count(hash) && (seen[hash] <= moves)) {
            return;
        }
        seen[hash] = moves;
        
        int j = 0;
        for (int i = 0; i < N; ++i) {
            if (cur[i] != val) {
                ++j;
                continue;
            }
            while ((j < N) && (cur[i] == cur[j])) ++j;
            int E = min(j - i, M - cur[i]);
            for (int k = E; k >= 1; --k) {
                place_tile(cur, i,  k);
                dfs(cur, moves + 1);
                place_tile(cur, i, -k);
            }
        }
    }
    
    lld get(vec<int>& cur) {
        lld sum = 0;
        for (int x: cur) {
            sum = 1LL * sum * (M + 1) + x;
        }
        return sum;
    }
    
    void place_tile(vec<int>& cur, int pos, int tile) {
        int E = abs(tile);
        for (int i = 0; i < E; ++i) {
            cur[pos + i] += tile;
        }
    }
};

/*
2
3
5
8
11
13
>> 3
>> 5
>> 6
*/
