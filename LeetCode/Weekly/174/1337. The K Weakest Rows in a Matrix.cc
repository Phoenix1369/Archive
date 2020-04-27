#define ALL(x) (x).begin(), (x).end()

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int N = mat.size();
        int M = mat[0].size();
        
        vector<int> numS;
        for (auto& row: mat) {
            auto itr = upper_bound(ALL(row), 1, greater<int>());
            int cnt = itr - row.begin();
            numS.push_back(cnt);
        }
        
        vector<int> ret;
        ret.reserve(N);
        for (int i = 0; i < N; ++i) {
            ret.push_back(i);
        }
        std::sort(ALL(ret), [&numS](int i, int j) {
            if (numS[i] != numS[j]) {
                return (numS[i] < numS[j]);
            }
            return (i < j);
        });
        ret.erase(ret.begin() + k, ret.end());
        return ret;
    }
};
