#define ALL(x) (x).begin(), (x).end()
unordered_map<int, int> C;
vector<int> D;

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        // Count
        int N = arr.size();
        C.clear();
        C.reserve(N);
        for (int n: arr) ++C[n];
        // Unique
        int M = C.size();
        if (k == 0) {
            return M;
        }
        D.clear();
        D.reserve(M);
        for (const auto& itr: C) {
            D.push_back(itr.second);
        }
        sort(ALL(D));
        // Aggregate
        int sum = 0;
        for (int i = 0; i < M; ++i) {
            sum += D[i];
            if (sum > k) {
                return M-i;
            } else if (sum == k) {
                return M-i-1;
            }
        }
        return -1;
    }
};
