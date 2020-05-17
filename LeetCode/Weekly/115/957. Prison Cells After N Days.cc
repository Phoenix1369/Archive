#define CLR(x) memset((x), -1, sizeof(x))
const int MAXC = 8;
const int MAXN = 1<<MAXC;
int seen[MAXN];
int A[MAXN];

class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        CLR(seen);
        int src = 0;
        for (int i = 0; i < MAXC; ++i) {
            src |= (cells[i] << i);
        }
        A[0] = src;
        seen[src] = 0;
        int off = 0;
        int end = MAXN;
        for (int i = 1; i < MAXN; ++i) {
            A[i] = advance(A[i-1]);
            if (seen[A[i]] != -1) {
                off = seen[A[i]];
                end = i - off;
                break;
            }
            seen[A[i]] = i;
        }
        int pos = (N < off) ? N :
            off + (N - off + end) % end;
        return result(A[pos]);
    }

private:
    int advance(int cur) {
        int nxt = 0;
        for (int i = 1; i+1 < MAXC; ++i) {
            if (test(cur, i-1) == test(cur, i+1)) {
                nxt |= (1 << i);
            }
        }
        return nxt;
    }
    
    vector<int> result(int num) {
        vector<int> ret(MAXC, 0);
        for (int i = 0; i < MAXC; ++i) {
            if (test(num, i)) {
                ret[i] = 1;
            }
        }
        return ret;
    }
    
    int test(int mask, int bit) {
        return (mask >> bit) & 1;
    }
};
