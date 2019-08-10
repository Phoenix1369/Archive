const int MAXN = 55;
const int MAXT = 3;
map<string,int> U, W;
string uu[MAXN], ww[MAXN];

struct Triple {
    // (t, u, w) timestamp, username, website
    int data[MAXT];

    bool operator < (const Triple& o) const {
        for (int i = 0; i < MAXT; ++i) {
            if (data[i] != o.data[i]) {
                return (data[i] < o.data[i]);
            }
        }
        return false;
    }

    int& u() { return data[1]; }
    int& w() { return data[2]; }
} A[MAXN];

map<Triple,int> cnt;
set<Triple> seen[MAXN];

class Solution {
public:
    vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
        init(U, uu, username);
        init(W, ww, website);

        int N = username.size();
        cnt.clear();
        for (int i = 0; i < N; ++i) {
            seen[i].clear();
        }
        for (int i = 0; i < N; ++i) {
            A[i] = Triple{timestamp[i], U[username[i]], W[website[i]]};
        }
        sort(A, A+N);

        // Generate all 3-sequences per user.
        auto ret = Triple{-1, -1, -1};
        for (int i = 0; i < N; ++i) {
            for (int j = i+1; j < N; ++j) {
                if (A[i].u() != A[j].u()) continue;

                for (int k = j+1; k < N; ++k) {
                    if (A[i].u() != A[k].u()) continue;

                    auto val = Triple{A[i].w(), A[j].w(), A[k].w()};
                    if (!seen[A[i].u()].count(val)) {
                        seen[A[i].u()].insert(val);

                        ++cnt[val];
                        if (cnt[val] > cnt[ret]) {
                            ret = val;
                        } else if ((cnt[val] == cnt[ret])
                                   && lex_less(val, ret)) {
                            ret = val;
                        }
                    }
                }
            }
        }

        vector<string> res;
        for (int i = 0; i < MAXT; ++i) {
            res.push_back(get(ret.data[i]));
        }
        return res;
     }

private:
    const string& get(int i) {
        return ww[i];
    }

    void init(map<string,int>& M, string (&arr)[MAXN], const vector<string>& V) {
        M.clear();
        for (auto s: V) {
            if (!M.count(s)) {
                int val = M.size();
                M[s] = val;
                arr[val] = s;
            }
        }
    }

    bool lex_less(const Triple& lhs, const Triple& rhs) {
        for (int i = 0; i < MAXT; ++i) {
            int c = get(lhs.data[i]).compare(get(rhs.data[i]));
            if (c) return (c < 0);
        }
        return false;
    }
};
