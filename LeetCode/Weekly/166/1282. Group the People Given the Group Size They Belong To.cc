class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int N = groupSizes.size();
        vector<vector<int>> G(N + 1, vector<int>());
        
        for (int i = 0; i < N; ++i) {
            G[groupSizes[i]].push_back(i);
        }
        vector<vector<int>> ret;
        for (int i = 1; i <= N; ++i) {
            while (!G[i].empty()) {
                vector<int> cur;
                for (int j = 0; j < i; ++j) {
                    cur.push_back(G[i].back());
                    G[i].pop_back();
                }
                ret.push_back(cur);
            }
        }
        return ret;
    }
};

/*
[3,3,3,3,3,1,3]
[2,1,3,3,3,2]
>> [[5],[0,1,2],[3,4,6]]
>> [[1],[0,5],[2,3,4]]
*/
