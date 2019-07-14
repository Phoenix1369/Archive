const int MAXN = 1e4+5;
const int VAL = 8;
int pre[MAXN];

class Solution {
    vector<int> A, S;
    int N;

public:
    int longestWPI(vector<int>& hours) {
        A = move(hours);
        N = A.size();
        A.insert(A.begin(), 0);
        pre[0] = 0;
        S.clear();
        S.push_back(0);

        int lo = 0;
        int ret = 0;
        for (int i = 1; i <= N; ++i) {
            pre[i] = pre[i-1] + ((A[i] > VAL) ? +1 : -1);
            if (pre[i] <= pre[S.back()]) {
                S.push_back(i);
            }
            ret = max(i - find(i), ret);
        }
        return ret;
    }

private:
    int find(int i) {
        int ss = S.size();
        int lo = 0;
        int hi = ss - 1;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (pre[i] - pre[S[mid]] > 0) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        if (lo == ss) {
            return i;
        }
        return S[lo];
    }
};
