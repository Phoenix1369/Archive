#define ALL(x) (x).begin(), (x).end()

class Solution {
    vector<int> copy;
    int N;

public:
    vector<int> sortArray(vector<int>& nums) {
        N = nums.size();
        copy = vector<int>(N, 0);
        mergesort(nums, 0, N);
        return nums;
    }

private:
    void merge(vector<int>& A, int l, int r) {
        for (int i = l; i < r; ++i) {
            copy[i] = A[i];
        }
        int m = (l + r) / 2;
        int i = l;
        int j = m;
        int k = l;
        while ((i < m) && (j < r)) {
            if (copy[i] <= copy[j]) {
                A[k++] = copy[i++];
            }
            else {
                A[k++] = copy[j++];
            }
        }
        while (i < m) A[k++] = copy[i++];
        while (j < r) A[k++] = copy[j++];
    }
    void mergesort(vector<int>& A, int l, int r) {
        if ((r - l) <= 1) {
            return;
        }
        int m = (l + r) / 2;
        mergesort(A, l, m);
        mergesort(A, m, r);
        merge(A, l, r);
    }
};