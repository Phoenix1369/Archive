vector<int> A;
int N;

class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        A = move(target);
        N = A.size();
        A.insert(A.begin(), 0);
        int ret = 0;
        for (int i = 0; i < N; ++i) {
            if (A[i] < A[i+1]) {
                ret += A[i+1] - A[i];
            }
        }
        return ret;
    }
};
