#define ALL(x) (x).begin(), (x).end()
typedef vector<int> vin;
const int MAXK = 5;
const int MAXN = 1005;
vin S[MAXN];

class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        for (int i = 0; i < MAXN; ++i) S[i].clear();
        for (auto row: items) {
            int id = row[0];
            int score = row[1];
            S[id].push_back(score);
        }
        vector<vin> ret;
        for (int i = 0; i < MAXN; ++i) {
            if (S[i].empty()) continue;
            sort(ALL(S[i]));
            int N = S[i].size();
            int sum = 0;
            for (int j = 1; j <= MAXK; ++j) {
                sum += S[i][N-j];
            }
            sum /= MAXK;
            ret.push_back({i, sum});
        }
        return ret;
    }
};
