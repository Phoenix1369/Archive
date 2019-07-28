#include <algorithm>
#include <cstdio>
const int MAXN = 55;
int P[MAXN];
int N;

bool solve() {
  int cnt = 0;
  for (int i = 1; i <= N; ++i) {
    if (P[i] != i) {
      ++cnt;
    }
  }
  return !cnt || (cnt == 2);
}

int main() {
  scanf("%d", &N);
  for (int i = 1; i <= N; ++i) {
    scanf("%d", &P[i]);
  }
  puts(solve() ? "YES" : "NO");
  return 0;
}
