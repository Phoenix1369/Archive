const vector<int> MT = {};
unordered_map<int, int> C;
unordered_set<int> seen;
vector<int> A;
vector<int> nxt;
int N;

struct Lake {
    int id, pos;

    bool operator < (const Lake& o) const {
        return o.pos < pos;
    }
};

class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        A = move(rains);
        N = A.size();
        init();
        compute();
        return solve();
    }

private:
    void compute() {
        for (int i = N-1; i >= 0; --i) {
            nxt[i] = C.count(A[i])
                ? C.at(A[i])
                : N;
            C[A[i]] = i;
        }
    }

    void init() {
        C.clear();
        C.reserve(N);
        nxt.assign(N, N);
        seen.clear();
        seen.reserve(N);
    }

    vector<int> solve() {
        vector<int> ret;
        priority_queue<Lake> Q;
        for (int i = 0; i < N; ++i) {
            if (A[i] > 0) {
                if (seen.count(A[i])) {
                    return MT;
                }
                Q.push({A[i], nxt[i]});
                ret.push_back(-1);
                seen.insert(A[i]);
            } else if (!seen.empty()) {
                Lake cur = Q.top();
                Q.pop();
                ret.push_back(cur.id);
                seen.erase(cur.id);
            } else {
                // dry any lake
                ret.push_back(1);
            }
        }
        return ret;
    }
};
