#define ALL(x) (x).begin(), (x).end()
const int MAXL = 2e4+5;
int cnt[MAXL];
int pos[MAXL];

class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int num_wanted, int use_limit) {
        for (int i = 0; i < MAXL; ++i) {
            cnt[i] = 0;
        }

        int N = values.size();
        iota(pos, pos + N, 0);
        sort(pos, pos + N, [&values](int lhs, int rhs) {
            return values[lhs] > values[rhs];
        });

        int num = 0;
        int sum = 0;
        for (int i = 0; (i < N) && (num < num_wanted); ++i) {
            if (cnt[labels[pos[i]]] == use_limit) {
                continue;
            }
            sum += values[pos[i]];
            ++cnt[labels[pos[i]]];
            ++num;
        }
        return sum;
    }
};
