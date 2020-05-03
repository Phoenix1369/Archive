const int MAXN = 305;
char S[MAXN];
int N;

struct Char {
    int cnt;
    char c;
    
    bool operator < (const Char& o) const {
        return o.cnt > cnt;
    }
};

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<Char> pq;
        pq.push({a, 'a'});
        pq.push({b, 'b'});
        pq.push({c, 'c'});
        Char skip{0, 0};
        N = 0;
        while (!pq.empty()) {
            auto cur = pq.top();
            pq.pop();
            if (!cur.cnt) break;
            S[N++] = cur.c;
            --cur.cnt;
            if (skip.c) {
                pq.push(skip);
                skip.c = 0;
            }
            if ((N >= 2) && (S[N-2] == cur.c)) {
                skip = cur;
            } else {
                pq.push(cur);
            }
        }
        S[N] = '\0';
        return S;
    }
};
