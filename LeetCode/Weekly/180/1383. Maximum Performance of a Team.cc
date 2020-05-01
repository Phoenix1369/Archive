typedef long long lld;
template <typename T>
using vec = vector<T>;

const int MAXN = 1e5+5;
const int MOD = 1e9+7;
int J[MAXN];
vec<int> S;

struct CMP {
    bool operator () (int lhs, int rhs) const {
        return S[rhs] < S[lhs];
    }
};

class Solution {
public:
    int maxPerformance(int N, vector<int>& speed, vector<int>& E, int K) {
        S = move(speed);
        iota(J, J+N, 0);
        sort(J, J+N, [&E](int lhs, int rhs) {
            return E[lhs] > E[rhs];
        });
        lld ret = 0LL;
        lld sum = 0LL;
        lld mne = 0LL;
        priority_queue<int, vec<int>, CMP> pq;
        for (int i = 0; i < N; ++i) {
            sum += S[J[i]];
            pq.push(J[i]);
            if (pq.size() > K) {
                int old = pq.top();
                pq.pop();
                sum -= S[old];
                if (old != J[i]) {
                    mne = J[i];
                }
            } else {
                mne = J[i];
            }
            ret = max(sum * E[mne], ret);
        }
        return ret % MOD;
    }
};
