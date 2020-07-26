#define ALL(x) (x).begin(), (x).end()

class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        int N = arr.size();
        sort(ALL(arr));
        int d = (arr[1] - arr[0]);
        for (int i = 2; i < N; ++i) {
            if (d != (arr[i] - arr[i-1])) {
                return false;
            }
        }
        return true;
    }
};
