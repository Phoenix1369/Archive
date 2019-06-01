class Solution {
    std::map<int,int> cnt;
    int head, left, ret;
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
        cnt.clear();
        int N = A.size();
        head = left = ret = 0;
        for (int i = 0; i < N; ++i) {
            ++cnt[A[i]];
            if (cnt.size() > K) {
                while ((head <= i) && (cnt.size() > K)) {
                    if (!--cnt[A[head]]) {
                        cnt.erase(A[head]);
                    }
                    ++head;
                }
                left = head;
            }
            while ((head <= i) && (cnt.size() == K) && (cnt[A[head]] > 1)) {
                --cnt[A[head]];
                ++head;
            }
            if (cnt.size() == K) {
                ret += head - left + 1;
            }
        }
        return ret;
    }
};
