#include <cstdio>
const int MAXN = 105;
char S[MAXN];
int N;

bool solve() {
  if (N & 1) {
    return false;
  }
  int K = N / 2;
  for (int i = 0; i < K; ++i) {
    if (S[i] != S[i+K]) {
      return false;
    }
  }
  return true;
}

int main() {
  scanf(" %d%s", &N, S);
  puts(solve() ? "Yes" : "No");
  return 0;
}
