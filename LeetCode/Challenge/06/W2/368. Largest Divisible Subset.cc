#define ALL(x) (x).begin(), (x).end()
unordered_map<int, int> C;
unordered_map<int, int> D;
vector<int> out;
int ans, N, ret;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        N = nums.size();
        sort(ALL(nums));
        C.clear();
        D.clear();
        C.reserve(N);
        D.reserve(N);
        ans = ret = 0;
        for (int x: nums) {
            int s = sqrt(x);
            int sz = 1;
            int up = 0;
            for (int i = 1; i <= s; ++i) {
                if ((x % i) != 0) {
                    continue;
                }
                int j = x / i;
                check(i, sz, up);
                check(j, sz, up);
            }
            C[x] = sz;
            D[x] = up;
            if (sz > ret) {
                ans = x;
                ret = sz;
            }
        }
        out.clear();
        while (ans) {
            out.push_back(ans);
            ans = D[ans];
        }
        return out;
    }

private:
    void check(int d, int& sz, int& up) {
        int c = C.count(d) ? C.at(d) : 0;
        if (c >= sz) {
            sz = c + 1;
            up = d;
        }
    }
};
