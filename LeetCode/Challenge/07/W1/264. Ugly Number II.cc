const int B = 3;
const int N = 1690;
const int BASE[B] = {2, 3, 5};
typedef long long lld;

struct State {
    array<int, B> exp;
    lld val;
    
    bool operator < (const State& o) const {
        return o.val < val;
    }
};
vector<int> A;
set<State> C;

class Solution {
public:
    int nthUglyNumber(int n) {
        if (A.empty()) {
            solve();
        }
        return A[n-1];
    }

private:
    void solve() {
        priority_queue<State> Q;
        State src{{0, 0, 0}, 1};
        C.insert(src);
        Q.push(src);
        while (A.size() < N) {
            State u = Q.top();
            A.push_back(u.val);
            Q.pop();
            for (int k = 0; k < B; ++k) {
                State v = u;
                ++v.exp[k];
                v.val *= BASE[k];
                if (C.count(v)) {
                    continue;
                }
                C.insert(v);
                Q.push(v);
            }
        }
    }
};
