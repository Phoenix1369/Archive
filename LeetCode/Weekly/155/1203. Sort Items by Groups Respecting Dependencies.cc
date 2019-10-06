#define ALL(x) (x).begin(), (x).end()
typedef vector<int> vin;
const int MAXN = 3e4+5;
const int MAXK = 2 * MAXN;
const int NOGR = -1;
const vin NOPE = {};
vector<vin> C, G, H;
vector<int> degG, degH;
int K, M, N;
int gID;
vin ret;

class Solution {
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        N = n;
        M = m;
        init();
        
        // Build graph.
        for (int i = 0; i < N; ++i) {
            if (group[i] == NOGR) {
                group[i] = gID++;
                
                C.emplace_back();
                H.emplace_back();
                degH.emplace_back();
            }
            C[group[i]].push_back(i);
        }
        for (int i = 0; i < N; ++i) {
            for (auto j: beforeItems[i]) {
                if (group[j] == group[i]) {
                    G[j].push_back(i);
                    ++degG[i];
                } else {
                    H[group[j]].push_back(group[i]);
                    ++degH[group[i]];
                }
            }
        }
        
        vin input(gID, 0);
        iota(ALL(input), 0);
        vin outer_order = tsort(H, degH, input);
        if (outer_order.size() != gID) {
            return NOPE;
        }
                
        for (int g: outer_order) {
            vin inner_order = tsort(G, degG, C[g]);
            if (inner_order.size() != C[g].size()) {
                return NOPE;
            }
            extend(ret, inner_order);
        }
        return ret;
    }

private:
    void extend(vin& A, vin& data) {
        A.reserve(A.size() + data.size());
        A.insert(A.end(), ALL(data));
    }
    
    void init() {
        K = N + M;
        gID = M;
        C.assign(M, vin{});
        
        G.assign(N, vin{});
        degG.assign(N, 0);
        
        H.assign(M, vin{});
        degH.assign(M, 0);
        
        ret.clear();
    }
    
    vin tsort(vector<vin>& adj, vin& deg, vin& input) {
        queue<int> Q;
        for (int node: input) {
            if (!deg[node]) {
                Q.push(node);
            }
        }
        vin order;
        while (!Q.empty()) {
            int cur = Q.front();
            Q.pop();
            order.push_back(cur);
            for (int nxt: adj[cur]) {
                if (!--deg[nxt]) {
                    Q.push(nxt);
                }
            }
        }
        return order;
    }
};
