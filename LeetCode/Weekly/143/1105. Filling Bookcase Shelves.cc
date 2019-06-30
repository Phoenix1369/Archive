const int MAXN = 1005;
const int INFN = MAXN * MAXN;
int dp[MAXN][MAXN];
// dp[i][j] = the total height of the first i books, with last row starting at j-th book.

class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelf_width) {
        int N = books.size();
        int K = shelf_width;
        books.insert(books.begin(), {0,0});
        for (int i = 0; i <= N; ++i) {
            for (int j = 0; j <= N; ++j) {
                dp[i][j] = INFN;
            }
        }
        dp[0][0] = 0;
        for (int i = 1; i <= N; ++i) {
            int w = books[i][0];
            int h = books[i][1];
            for (int j = i-1; j >= 0; --j) {
                dp[i][i] = min(dp[i-1][j], dp[i][i]);
            }
            dp[i][i] += h;
            for (int j = i-1; j >= 1; --j) {
                w += books[j][0];
                if (w > shelf_width) {
                    break;
                }
                h = max(books[j][1], h);
                dp[i][j] = (dp[j][j] - books[j][1]) + h;
            }
        }
        int res = INFN;
        for (int i = 1; i <= N; ++i) {
            res = min(dp[N][i], res);
        }
        return res;
    }
};
