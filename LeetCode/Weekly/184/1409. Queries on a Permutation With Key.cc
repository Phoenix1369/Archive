#define ALL(x) (x).begin(), (x).end()

class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        vector<int> P(m, 0);
        vector<int> ret;
        iota(ALL(P), 1);
        ret.reserve(m);
        for (int x: queries) {
            int pos = 0;
            while (P[pos] != x) ++pos;
            ret.push_back(pos);
            for (int i = pos-1; i >= 0; --i) {
                swap(P[i], P[i+1]);
            }
        }
        return ret;
    }
};
