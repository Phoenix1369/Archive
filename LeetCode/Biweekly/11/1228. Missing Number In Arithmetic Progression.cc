class Solution {
public:
    int missingNumber(vector<int>& arr) {
        int N = arr.size();
        int diff = (arr.back() - arr[0]) / N;
        for (int i = 1; i < N; ++i) {
            int nd = arr[i] - arr[i-1];
            if (nd != diff) {
                return arr[i-1] + diff;
            }
        }
        return arr[0];
    }
};
