class Solution {
public:
    vector<int> transformArray(vector<int>& arr) {
        int N = arr.size();
        vector<int> ret = arr;
        bool change = true;
        while (change) {
            change = false;
            for (int i = 1; i < N-1; ++i) {
                if (ret[i] > std::max(arr[i-1], arr[i+1])) {
                    change = true;
                    --ret[i];
                } else if (ret[i] < std::min(arr[i-1], arr[i+1])) {
                    change = true;
                    ++ret[i];
                }
            }
            arr = ret;
        }
        return ret;
    }
};
