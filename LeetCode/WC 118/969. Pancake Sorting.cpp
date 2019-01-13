const int MAXN = 105;
int p[MAXN];

class Solution {
public:
    vector<int> pancakeSort(vector<int>& A) {
        int n = A.size();
        vector<int> ret;
        for (int i = n-1; i > 0; --i) {
            if (A[i] == i+1) continue;
            if (A[0] != i+1) {
                int p;
                for (int j = 0; j < i; ++j) {
                    if (A[j] == i+1) {
                        p = j;
                        break;
                    }
                }
                for (int j=0, k=p; j < k; ++j, --k) {
                    swap(A[j], A[k]);
                }
                ret.push_back(p+1);
            }
            for (int j=0, k=i; j < k; ++j, --k) {
                swap(A[j], A[k]);
            }
            ret.push_back(i+1);
        }
        return ret;
    }
};
