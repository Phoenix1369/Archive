const int MAXN = 3e4+5;

struct SegmentTree {
    int data[MAXN<<2]{ };

    void build(int f, int l, int r) {
        int g=f<<1, m=(l+r)>>1;
        if(l == r) {
            data[f] = -1;
            return;
        }
        build(g  , l  , m);
        build(g|1, m+1, r);
        data[f] = -1;
    }

    void insert(int key, int val) {
        insert(1, 1, MAXN-1, key, val);
    }

    int get(int u, int v) {
        return get(1, 1, MAXN-1, u, v);
    }

private:
    int get(int f, int l, int r, int u, int v) {
        if((u > r) || (v < l)) return -1;
        if((u <= l) && (r <= v)) {
            return data[f];
        }
        int g=f<<1, m=(l+r)>>1;
        return std::max(
            get(g  , l  , m, u, v),
            get(g|1, m+1, r, u, v)
        );
    }

    void insert(int f, int l, int r, int k, int v) {
        int g=f<<1, m=(l+r)>>1;
        if(l > r) return;
        if(l == r) {
            data[f] = v;
            return;
        }
        if(k <= m) {
            insert(g  , l  , m, k, v);
        } else {
            insert(g|1, m+1, r, k, v);
        }
        data[f] = std::max(data[g], data[g|1]);
    }
} segtr;

class Solution {
    int MOD = 1e9+7;
    int prv[MAXN]{ };
    int nxt[MAXN]{ };
public:
    int sumSubarrayMins(vector<int>& A) {
        reset();

        int N = (int)A.size();
        segtr.build(1, 1, MAXN-1);
        segtr.insert(1, -1);
        for(int i = 0; i < N; ++i) {
            prv[i] = segtr.get(1, A[i]);
            segtr.insert(A[i], i);
        }
        segtr.build(1, 1, MAXN-1);
        segtr.insert(1, -1); // Flip indices
        for(int i = N-1; i >= 0; --i) {
            nxt[i] = N-segtr.get(1, A[i]-1)-1;
            segtr.insert(A[i], N-i-1);
        }

        int ret = 0;
        for(int i = 0; i < N; ++i) {
            ret = (1LL * A[i] * (i-prv[i]) % MOD * (nxt[i]-i) % MOD + ret) % MOD;
        }
        return ret;
    }

    void reset() {
        for(int i = 0; i < MAXN; ++i) {
            nxt[i] = prv[i] = 0;
        }
    }
};
