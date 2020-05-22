const int MAXC = 5e4+5;
const int MAXN = 100;
unordered_map<string, int> C;
bitset<MAXC> G[MAXN];
int id, N;

class Solution {
public:
    vector<int> peopleIndexes(vector<vector<string>>& A) {
        N = A.size();
        init();
        
        for (int i = 0; i < N; ++i) {
            for (const auto& s: A[i]) {
                if (!C.count(s)) {
                    C[s] = id++;
                }
                G[i].set(C.at(s));
            }
        }
        
        vector<int> ret;
        for (int i = 0; i < N; ++i) {
            const auto& val = G[i];
            auto pred = [&val](const auto& mask) {
                return (val & mask) == val;
            };
            if (none_of(G    , G+i, pred) &&
                none_of(G+i+1, G+N, pred)) {
                ret.push_back(i);
            }
        }
        return ret;
    }

private:
    void init() {
        C.clear();
        C.reserve(MAXC);
        for (int i = 0; i < N; ++i) {
            G[i].reset();
        }
        id = 0;
    }
};
