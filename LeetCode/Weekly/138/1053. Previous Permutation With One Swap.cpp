map<int,int> memo;

class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& A) {
        int N = A.size();
        memo.clear();
        for (int i = N-1; i >= 0; --i) {
            auto itr = memo.lower_bound(A[i]);
            if (itr != memo.begin()) {
                --itr;
                swap(A[i], A[itr->second]);
                break;
            }
            memo[A[i]] = i;
        }
        return A;
    }
};
