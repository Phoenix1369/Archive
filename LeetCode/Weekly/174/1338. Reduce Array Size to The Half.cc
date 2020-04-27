#define ALL(x) (x).begin(), (x).end()
vector<int> B;
int M, N;

class Solution {
public:
    int minSetSize(vector<int>& arr) {
        N = arr.size();
        sort(ALL(arr));
        count(arr);
        M = B.size();
        sort(ALL(B));
        int N2 = N/2;
        int ret = 0;
        int sum = 0;
        for (int i = M-1; (i >= 0) && (sum < N2); --i) {
            sum += B[i];
            ++ret;
        }
        return ret;
    }

private:
    void count(const vector<int>& A) {
        B.clear();
        B.reserve(N);
        int cnt = 1;
        for (int i = 1; i < N; ++i) {
            if (A[i] != A[i-1]) {
                B.push_back(cnt);
                cnt = 0;
            }
            ++cnt;
        }
        B.push_back(cnt);
    }
};
