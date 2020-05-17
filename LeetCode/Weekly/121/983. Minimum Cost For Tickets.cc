#define CLR(x) memset((x), false, sizeof(x))
const int MAXD = 366;
bool trip[MAXD];
int dp[MAXD];

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        CLR(trip);
        for (int d: days) {
            trip[d] = true;
        }
        dp[0] = 0;
        for (int i = 1; i < MAXD; ++i) {
            if (!trip[i]) {
                dp[i] = dp[i-1];
                continue;
            }
            dp[i] = min(
                dp[i-1] + costs[0], min(
                    dp[max(i-7 , 0)] + costs[1],
                    dp[max(i-30, 0)] + costs[2]
                )
            );
        }
        return dp[MAXD-1];
    }
};
