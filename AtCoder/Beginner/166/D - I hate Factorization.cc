#include <cstdio>
#include <utility>
typedef long long lld;
const int MAXN = 121;
lld F[MAXN];
int K, X;

lld pow5(int n) { return 1LL*n*n*n*n*n; }

std::pair<int,int> solve() {
  for (int i = 0; i < MAXN; ++i) {
    for (int j = i; j < MAXN; ++j) {
      if (F[i] - F[j] == X) {
        return {i, j};
      } else if (F[i] + F[j] == X) {
        return {i, -j};
      } else if (F[j] - F[i] == X) {
        return {j, i};
      }
    }
  }
  return {0, 0};
}

void init() {
  for (int i = 0; i < MAXN; ++i) {
    F[i] = pow5(i);
  }
}

int main() {
  scanf("%d", &X);
  init();
  auto ret = solve();
  printf("%d %d\n", ret.first, ret.second);
  return 0;
}
