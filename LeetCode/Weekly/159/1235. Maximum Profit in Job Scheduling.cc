const int MAXN = 1e5+5;
map<int,int> C;
int dp[MAXN];
vector<int> seg[MAXN];
int N;

class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {        
        N = startTime.size();
        C.clear();
        for (int i = 0; i < N; ++i) {
            C[startTime[i]] = 0;
            C[endTime[i]] = 0;
        }
        int K = 0;
        for (auto& itr: C) {
            itr.second = ++K;
        }
        for (int i = 0; i <= K; ++i) {
            seg[i].clear();
        }
        for (int i = 0; i < N; ++i) {
            int end = C.at(endTime[i]);
            seg[end].push_back(i);
        }

        dp[0] = 0;
        for (int i = 1; i <= K; ++i) {
            dp[i] = dp[i-1];
            for (int j: seg[i]) {
                int beg = C.at(startTime[j]);
                dp[i] = max(dp[beg] + profit[j], dp[i]);
            }
        }
        return dp[K];
    }
};

/*
[1,2,3,3]
[3,4,5,6]
[50,10,40,70]
[1,2,3,4,6]
[3,5,10,6,9]
[20,20,100,70,60]
[1,1,1]
[2,3,4]
[5,6,4]
>> 120
>> 150
>> 6
*/
