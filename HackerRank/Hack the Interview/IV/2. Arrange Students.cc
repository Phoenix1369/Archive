#include <algorithm>
#include <cstdio>
const int MAXN = 105;
int B[MAXN];
int G[MAXN];
int N, T;

bool less(int* one, int* two) {
  bool yes = true;
  for (int i = 0; i < N; ++i) {
    if (i) yes &= (two[i-1] <= one[i]);
    yes &= (one[i] <= two[i]);
  }
  return yes;
}

bool solve() {
  std::sort(B, B + N);
  std::sort(G, G + N);
  return less(B, G) || less(G, B);
}

int main() {
  scanf("%d", &T);
  for (int t = 0; t < T; ++t) {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
      scanf("%d", &B[i]);
    }
    for (int i = 0; i < N; ++i) {
      scanf("%d", &G[i]);
    }
    puts(solve() ? "YES" : "NO");
  }
}
