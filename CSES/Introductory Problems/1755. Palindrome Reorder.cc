#include <cstdio>
#include <cstring>
const int MAXA = 26;
const int MAXS = 1e6+5;
int cnt[MAXA]{ };
char  P[MAXS];
char  S[MAXS];
int K, N;

void solve() {
  for (int i = 0; i < N; ++i) {
    ++cnt[S[i]-'A'];
  }
  int odd = 0;
  for (int i = 0; i < MAXA; ++i) {
    if (cnt[i] & 1) ++odd;
  }
  if (odd > 1) {
    puts("NO SOLUTION");
    return;
  }
  char M = '\0';
  for (int i = 0; i < MAXA; ++i) {
    char c = 'A' + i;
    if (cnt[i] & 1) {
      M = c;
    }
    cnt[i] >>= 1;
    for (int j = 0; j < cnt[i]; ++j) {
      P[K] = P[N-K-1] = c;
      ++K;
    }
  }
  if (odd) {
    P[K++] = M;
  }
  P[N] = '\0';
  puts(P);
}

int main() {
  scanf(" %s", S);
  N = strlen(S);
  solve();
  return 0;
}
