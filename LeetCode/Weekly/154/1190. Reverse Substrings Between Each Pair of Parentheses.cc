#define ALL(x) (x).begin(), (x).end()
const int MAXN = 2005;
int P[MAXN];
vector<int> S;
string A;
int N;

class Solution {
public:
    string reverseParentheses(string s) {
        A = move(s);
        N = A.size();
        match_pairs();
        return dfs(0, N-1);
    }
    
private:
    string dfs(int l, int r) {
        if ((l > r) || (r >= N)) {
            return "";
        }
        if (A[l] == '(') {
            string res = dfs(l + 1, P[l] - 1);
            reverse(ALL(res));
            return res + dfs(P[l] + 1, r);
        }
        return A[l] + dfs(l + 1, r);
    }
    
    void match_pairs() {
        S.clear();
        for (int i = 0; i < N; ++i) {
            if (A[i] == '(') {
                S.push_back(i);
            } else if (A[i] == ')') {
                P[S.back()] = i;
                S.pop_back();
            }
        }
    }
};
