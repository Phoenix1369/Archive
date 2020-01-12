const int MAXN = 3e4+5;
int pre[MAXN];

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int N = arr.size();
        pre[0] = 0;
        for (int i = 0; i < N; ++i) {
            pre[i+1] = pre[i] ^ arr[i];
        }
        vector<int> ret;
        for (auto& query: queries) {
            int l = query[0];
            int r = query[1];
            ++r;
            ret.push_back(pre[r] ^ pre[l]);
        }
        return ret;
    }
};

/*
[1,3,4,8]
[[0,1],[1,2],[0,3],[3,3]]
[4,8,2,10]
[[2,3],[1,3],[0,0],[0,3]]
>> [2,7,14,8]
>> [8,0,4,4]
*/
