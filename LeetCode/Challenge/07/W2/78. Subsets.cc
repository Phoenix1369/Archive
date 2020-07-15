template <typename T>
using vec = vector<T>;

vec<vec<int>> ret;
vec<int> A;
vec<int> C;
int N;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        A = move(nums);
        N = A.size();
        ret.clear();
        dfs(0);
        return ret;
    }

private:
    void dfs(int pos) {
        if (pos == N) {
            ret.push_back(C);
            return;
        }
        C.push_back(A[pos]);
        dfs(pos+1);
        C.pop_back();
        dfs(pos+1);
    }
};
