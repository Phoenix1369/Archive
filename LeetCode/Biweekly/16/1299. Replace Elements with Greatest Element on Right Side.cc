class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int N = arr.size();
        int best = -1;
        for (int i = N-1; i >= 0; --i) {
            int temp = arr[i];
            arr[i] = best;
            best = max(temp, best);
        }
        return arr;
    }
};
