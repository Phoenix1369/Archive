#include <algorithm>
#include <cstdio>
#include <map>
#include <utility>
#define x first
#define y second
typedef std::pair<int,int> pii;
const int MAXN = 2e5+5;
const int MOD = 998244353;
std::map<int,int> X, Y;
int two[MAXN];
pii S[MAXN];
int N;

struct SegmentTree {
  int data[MAXN<<2];

  void build() {
    return build(1, 1, N);
  }

  int get(int i, int j) {
    if (i > j) return 0;
    return get(1, 1, N, i, j);
  }

  void set(int i, int v) {
    return set(1, 1, N, i, v);
  }

private:
  void build(int f, int l, int r) {
    if (l == r) return;

    int g = f<<1;
    int m = (l+r)/2;
    build(g  , l  , m);
    build(g|1, m+1, r);
    data[f] = 0;
  }

  int get(int f, int l, int r, int i, int j) {
    if (j < l || r < i) return 0;
    if (i <= l && r <= j) return data[f];

    int g = f<<1;
    int m = (l+r)/2;
    return
      get(g  , l  , m, i, j) +
      get(g|1, m+1, r, i, j);
  }

  void set(int f, int l, int r, int i, int v) {
    if (i < l || r < i) return;
    if (l == r) {
      if (i == l) data[f] = v;
      return;
    }
    int g = f<<1;
    int m = (l+r)/2;
    set(g  , l  , m, i, v);
    set(g|1, m+1, r, i, v);
    data[f] = data[g] + data[g|1];
  }
} segtr;

void init() {
  two[0] = 1;
  for (int i = 1; i < MAXN; ++i) {
    two[i] = 2LL * two[i-1] % MOD;
  }
}

int main() {
  init();
  scanf("%d", &N);
  for (int i = 0; i < N; ++i) {
    scanf(" %d%d", &S[i].x, &S[i].y);
    X[S[i].x] = 0;
    Y[S[i].y] = 0;
  }
  // Coordinate Compression
  int xn = 0;
  for (auto& xtr: X) xtr.second = ++xn;
  int yn = 0;
  for (auto& ytr: Y) ytr.second = ++yn;
  for (int i = 0; i < N; ++i) {
    S[i].x = X[S[i].x];
    S[i].y = Y[S[i].y];
  }
  std::sort(S, S+N);
  segtr.build();

  int ret = 0;
  for (int i = 0; i < N; ++i) {
    int NN = N - S[i].y;
    int SS = S[i].y - 1;
    int NW = segtr.get(S[i].y + 1, N);
    int SW = segtr.get(1, S[i].y - 1);
    int sum = two[N];
    sum = (1LL * sum - two[NN] + MOD) % MOD; // N
    sum = (1LL * sum - two[SS] + MOD) % MOD; // S
    sum = (1LL * sum - two[N - S[i].x] + MOD) % MOD; // E
    sum = (1LL * sum - two[S[i].x - 1] + MOD) % MOD; // W
    sum = (1LL * sum + two[NN - NW]) % MOD; // NE
    sum = (1LL * sum + two[SS - SW]) % MOD; // SE
    sum = (1LL * sum + two[NW]) % MOD; // NW
    sum = (1LL * sum + two[SW]) % MOD; // SW
    sum = (sum + MOD - 1) % MOD; // empty set
    segtr.set(S[i].y, 1);
    ret = (1LL * ret + sum) % MOD;
  }
  printf("%d\n", ret);
  return 0;
}
