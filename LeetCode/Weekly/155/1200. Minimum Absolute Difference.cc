#define ALL(x) (x).begin(), (x).end()
const int MAXN = 2e6+5;

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int N = arr.size();
        sort(ALL(arr));
        
        int best = MAXN;
        for (int i = 1; i < N; ++i) {
            best = min(arr[i] - arr[i-1], best);
        }
        vector<vector<int>> ret;
        for (int i = 1; i < N; ++i) {
            if ((arr[i] - arr[i-1]) == best) {
                ret.push_back({arr[i-1], arr[i]});
            }
        }
        return ret;
    }
};
