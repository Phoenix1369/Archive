#define ALL(x) (x).begin(), (x).end()

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int N = arr.size();
        vector<int> I(N, 0);
        for (int i = 0; i < N; ++i) {
            I[i] = i;
        }
        sort(ALL(I), [&arr](int lhs, int rhs) {
            return (arr[lhs] < arr[rhs]);
        });
        
        int C = 0;
        vector<int> ret(N, 0);
        for (int i = 0; i < N; ++i) {
            if (!i || (arr[I[i]] != arr[I[i-1]])) {
                ++C;
            }
            ret[I[i]] = C;
        }
        return ret;
    }
};
