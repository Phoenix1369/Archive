const int MAXA = 26;
const int MAXN = 1e5+5;
int pre[MAXN][MAXA]{ };
string S;
int N, Q;

class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        S = move(s);
        N = S.size();
        Q = queries.size();
        
        init();
        
        vector<bool> ret;
        ret.reserve(Q);
        for (auto q: queries) {
            ret.push_back(possible(q[0], q[1], q[2]));
        }
        return ret;
    }
    
private:
    void init() {
        for (int i = 0; i <= N; ++i) {
            for (int j = 0; j < MAXA; ++j) {
                pre[i][j] = 0;
            }
        }
        for (int i = 1; i <= N; ++i) {
            ++pre[i][S[i-1]-'a'];
            for (int j = 0; j < MAXA; ++j) {
                pre[i][j] += pre[i-1][j];
            }
        }
    }
    
    bool possible(int left, int right, int k) {
        int odd = 0;
        for (int j = 0; j < MAXA; ++j) {
            // Only replace (match) unpaired letters.
            int val = pre[right+1][j] - pre[left][j];
            if (val & 1) ++odd;
        }
        // The middle character is arbitrary.
        if ((right - left + 1) & 1) --odd;
        return (odd <= k*2);
    }
};
