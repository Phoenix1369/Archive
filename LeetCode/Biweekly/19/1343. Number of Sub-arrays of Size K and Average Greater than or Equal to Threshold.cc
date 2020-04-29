class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int K, int threshold) {
        int N = arr.size();
        int V = K * threshold;
        int sum = 0;
        int ret = 0;
        for (int i = 0; i < N; ++i) {
            if (i >= K) {
                sum -= arr[i-K];
            }
            sum += arr[i];
            if ((i + 1 >= K) && (sum >= V)) ++ret;
        }
        return ret;
    }
};
