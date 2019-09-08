const int INFN = 1e9+7;
const int MAXN = 4005;
const int NOPE = -1;
bool inB[MAXN]{ };
int dp[MAXN][MAXN];
int mp[MAXN][MAXN];
map<int,int> C;
int K, M, N;

// dp[i][j] = min moves using first i of arr1, to end with element j.

class Solution {
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {        
        N = arr1.size();
        M = arr2.size();
        
        // Coordinate compression.
        C.clear();
        for (int num: arr1) C[num] = 0;
        for (int num: arr2) C[num] = 0;
        K = 0;
        for (auto& itr: C) {
            itr.second = ++K;
        }
        for (int& num: arr1) num = C[num];
        for (int& num: arr2) num = C[num];
        
        // Init after setting N, M, K.
        for (int i = 1; i <= K; ++i) inB[i] = false;
        for (int& num: arr2) inB[num] = true;
        
        for (int i = 0; i <= N; ++i) {
            for (int j = 0; j <= K; ++j) {
                dp[i][j] = mp[i][j] = ((i == 0) ? 0 : INFN);
            }
        }
        
        arr1.insert(arr1.begin(), 0); // Leading zero.
        
        // Solve.
        for (int i = 1; i <= N; ++i) {
            int end = K - N + i;
            for (int j = 1; j <= end; ++j) {
                bool same = (arr1[i] == j);
                if (inB[j] || same) {
                    dp[i][j] = mp[i-1][j-1];
                    if (!same) ++dp[i][j];
                } else {
                    dp[i][j] = INFN;
                }
                mp[i][j] = min(mp[i][j-1], dp[i][j]);
            }
        }
        
        // Read table.
        int ret = INFN;
        for (int j = N; j <= K; ++j) {
            ret = min(dp[N][j], ret);
        }
        if (ret >= INFN) {
            ret = NOPE;
        }
        return ret;
    }
};
