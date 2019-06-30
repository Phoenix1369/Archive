const int MAXN = 2e4+5;
int match[MAXN]; // operator -> closing.

class Solution {
    string E;
    int N;

    vector<int> paren;

public:
    bool parseBoolExpr(string expression) {
        E = move(expression);
        N = E.size();

        for (int i = 0; i < N; ++i) {
            if (E[i] == '(') {
                paren.push_back(i);
            } else if (E[i] == ')') {
                match[paren.back() - 1] = i;
                paren.pop_back();
            } else if (E[i] == 't' || E[i] == 'f') {
                match[i] = i;
            }
        }
        return dfs(0, N-1);
    }

    bool dfs(int l, int r) {
        if (l == r) {
            return (E[l] == 't');
        }
        if (E[l] == '!') {
            return !dfs(l + 2, r - 1);
        }
        if (E[l] == '|') {
            int head = l + 2;
            bool res = false;
            while (!res && (head < r)) {
                if (E[head] == 't') {
                    res = true;
                } else if (E[head] != 'f') {
                    if (dfs(head, match[head])) {
                        res = true;
                    }
                }
                head = match[head] + 2;
            }
            return res;
        } else {
            int head = l + 2;
            bool res = true;
            while (res && (head < r)) {
                if (E[head] == 'f') {
                    res = false;
                } else if (E[head] != 't') {
                    if (!dfs(head, match[head])) {
                        res = false;
                    }
                }
                head = match[head] + 2;
            }
            return res;
        }
    }
};
