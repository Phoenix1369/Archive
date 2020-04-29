class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        int N = arr.size();
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (i == j) continue;
                if (arr[i] == 2 * arr[j]) {
                    return true;
                }
            }
        }
        return false;
    }
};
