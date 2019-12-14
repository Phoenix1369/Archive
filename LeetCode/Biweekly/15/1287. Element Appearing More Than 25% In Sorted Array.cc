class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int N = arr.size();
        int N4 = N / 4;
        int cnt = 1;
        for (int i = 1; i < N; ++i) {
            if (arr[i] != arr[i-1]) {
                if (cnt > N4) {
                    return arr[i-1];
                }
                cnt = 1;
            } else {
                ++cnt;
            }
        }
        return arr[N-1];
    }
};
