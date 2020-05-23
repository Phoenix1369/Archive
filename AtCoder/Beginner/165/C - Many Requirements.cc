#include <algorithm>
#include <cstdio>
const int MAXN = 15;
const int MAXQ = 55;
int a[MAXQ], b[MAXQ], c[MAXQ], d[MAXQ];
int A[MAXN];
int M, N, Q;
int ret;

void dfs(int pos, int u) {
  if (pos > N) {
    int sum = 0;
    for (int i = 0; i < Q; ++i) {
      if (A[b[i]] - A[a[i]] == c[i]) {
        sum += d[i];
      }
    }
    ret = std::max(sum, ret);
    return;
  }
  for (int v = u; v <= M; ++v) {
    A[pos] = v;
    dfs(pos+1, v);
  }
}
    

int main() {
  scanf(" %d%d%d", &N, &M, &Q);
  for (int i = 0; i < Q; ++i) {
    scanf(" %d%d%d%d", &a[i], &b[i], &c[i], &d[i]);
  }
  ret = 0;
  dfs(1, 1);
  printf("%d\n", ret);
  return 0;
}
