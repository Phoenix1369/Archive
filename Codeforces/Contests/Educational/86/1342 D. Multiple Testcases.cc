#include <algorithm>
#include <cstdio>
#include <vector>
const int MAXN = 2e5+5;
int C[MAXN];
int cnt[MAXN];
int K, M, N;

std::vector<int> A[MAXN];
int B;

int estimate() {
  int sum = 0;
  int ret = 0;
  for (int i = K; i >= 1; --i) {
    sum += cnt[i];
    int val = (sum + C[i] - 1) / C[i];
    ret = std::max(val, ret);
  }
  return ret;
}

void solve() {
  int k = 0;
  for (int i = 1; i <= K; ++i) {
    for (int j = 0; j < cnt[i]; ++j) {
      A[k % B].push_back(i);
      ++k;
    }
  }
}

void output() {
  printf("%d\n", B);
  for (int i = 0; i < B; ++i) {
    printf("%lu",A[i].size());
    for (int& x: A[i]) {
      printf(" %d", x);
    }
    putchar('\n');
  }
}

int main() {
  scanf(" %d%d", &N, &K);
  for (int i = 1; i <= K; ++i) {
    cnt[i] = 0;
  }
  for (int i = 1; i <= N; ++i) {
    scanf("%d", &M);
    ++cnt[M];
  }
  for (int i = 1; i <= K; ++i) {
    scanf("%d", &C[i]);
  }
  B = estimate();
  solve();
  output();
  return 0;
}
