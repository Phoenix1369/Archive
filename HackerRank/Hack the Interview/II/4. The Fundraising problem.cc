#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
#define ALL(x) (x).begin(), (x).end()
#define CLR(x) memset((x), -1, sizeof(x))
typedef long long lld;
typedef std::vector<int> vin;
const int MAXN = 15;
const int EXPN = 1<<MAXN;
int C[MAXN+1][MAXN];
int G[MAXN][MAXN];
int X[MAXN];
int K, M, N, S, T;

lld dp[2][EXPN];
lld P[MAXN+1][EXPN];
int L;

lld solve() {
  CLR(dp);
  dp[0][0] = 0;
  for (int h = 1; h <= M; ++h) {
    int i = (h & 1);
    for (int mask = 0; mask < L; ++mask) {
      dp[i][mask] = dp[i^1][mask];
      for (int s = mask; s; s = (s - 1) & mask) {
        if ((dp[i^1][mask & ~s] == -1) || (P[h][s] == -1)) {
          continue;
        }
        dp[i][mask] = std::max(dp[i][mask], dp[i^1][mask & ~s] + P[h][s]);
      }
    }
  }
  return dp[M & 1][L - 1];
}

lld approach(int i, int mask) {
  // "i"-th student group approach "mask" guest tables
  vin gen;
  for (int bit = 0; bit < S; ++bit) {
    if ((mask >> bit) & 1) {
      for (int k = 0; k < X[bit]; ++k) {
        gen.push_back(G[bit][k]);
      }
    }
  }
  if (gen.size() > 1u * K * N) {
    return -1;
  }
  int sz = gen.size();
  std::sort(ALL(gen));
  lld don = 0;
  int cnt = K;
  int j = N-1;
  for (int k = sz-1; k >= 0; --k) {
    don += 1LL * C[i][j] * gen[k];
    if (!--cnt) {
      cnt = K;
      --j;
    }
  }
  return don;
}

void init() {
  for (int i = 1; i <= M; ++i) {
    for (int mask = 0; mask < L; ++mask) {
      P[i][mask] = approach(i, mask);
    }
  }
}

void fastio() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
}

int main() {
  fastio();
  std::cin >> T;
  for (int t = 0; t < T; ++t) {
    std::cin >> M >> N >> S;
    for (int i = 1; i <= M; ++i) {
      for (int j = 0; j < N; ++j) {
        std::cin >> C[i][j];
      }
      std::sort(C[i], C[i] + N);
    }
    for (int i = 0; i < S; ++i) {
      std::cin >> X[i];
      for (int j = 0; j < X[i]; ++j) {
        std::cin >> G[i][j];
      }
    }
    std::cin >> K;
    L = (1 << S);
    init();
    std::cout << solve() << '\n';
  }
  return 0;
}
