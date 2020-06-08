#define ALL(x) (x).begin(), (x).end()
vector<int> A;
int N;

class Solution {
public:
    Solution(vector<int>& w) {
        srand(time(nullptr));
        A = move(w);
        N = A.size();
        for (int i = 1; i < N; ++i) {
            A[i] += A[i-1];
        }
    }

    int pickIndex() {
        int val = rand() % A.back();
        ++val;
        return lower_bound(ALL(A), val) - A.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
