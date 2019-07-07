const int MAXN = 1e4+5;
int match[MAXN];

class Solution {
    vector<int> ret, S;
    int n;

public:
    vector<int> maxDepthAfterSplit(string seq) {
        n = seq.size();
        ret.assign(n, 0);
        S.clear();

        for (int i = 0; i < n; ++i) {
            if (seq[i] == '(') {
                S.push_back(i);
            } else {
                match[S.back()] = i;
                S.pop_back();
            }
        }
        int head = 0;
        while (head < n) {
            dfs(head, match[head], 0);
            head = match[head] + 1;
        }
        return ret;
    }

private:
    void dfs(int l, int r, int k) {
        ret[l] = ret[r] = k;
        int head = l + 1;
        while (head < r) {
            dfs(head, match[head], k ^ 1);
            head = match[head] + 1;
        }
    }
};
