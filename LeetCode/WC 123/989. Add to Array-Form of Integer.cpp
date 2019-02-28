class Solution {
    const int BASE = 10;
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        vector<int> ret;
        int carry = K;
        int N = A.size();
        for (int i = N-1; i >= 0; --i) {
            carry += A[i];
            ret.push_back(carry % BASE);
            carry /= BASE;
        }
        while (carry) {
            ret.push_back(carry % BASE);
            carry /= BASE;
        }
        std::reverse(ret.begin(), ret.end());
        return ret;
    }
};
