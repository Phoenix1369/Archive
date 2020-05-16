const int MAXN = 305;
int A[MAXN];
int N;

// Find all (i, j, k) satisfying:
//   (A[k] ^ A[j-1]) == (A[j-1] ^ A[i-1])
//   A[k] == A[i-1]

class Solution {
public:
    int countTriplets(vector<int>& arr) {
        N = arr.size();
        A[0] = 0;
        for (int i = 1; i <= N; ++i) {
            A[i] = A[i-1] ^ arr[i-1];
        }
        int ret = 0;
        for (int k = 1; k <= N; ++k) {
            for (int i = 1; i < k; ++i) {
                if (A[i-1] == A[k]) ret += k-i;
            }
        }
        return ret;
    }
};
