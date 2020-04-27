#include <cstdio>
const int MAXA = 26;
const int MAXN = 3e5+5;
int cnt[MAXN][MAXA];
int pos[MAXN][MAXA];
char S[MAXN];
int N, Q;

void init() {
  // Lowercase
  for (int i = 1; i <= N; ++i) {
    if (S[i] <= 'Z') S[i] += ' ';
  }

  // Reset Table
  for (int j = 0; j < MAXA; ++j) {
      pos[0][j] = 0;
      cnt[0][j] = 0;
  }
}

char find_greatest(int x, int y) {
  for (char c = 'z'; c >= 'a'; --c) {
    if (pos[y][c-'a'] >= x) {
      return c;
    }
  }
  return 0;
}

void solve() {
  for (int i = 1; i <= N; ++i) {
      for (int j = 0; j < MAXA; ++j) {
          pos[i][j] = pos[i-1][j];
          cnt[i][j] = cnt[i-1][j];
      }
      pos[i][S[i]-'a'] = i;
      ++cnt[i][S[i]-'a'];
  }

  for (int q = 0; q < Q; ++q) {
    int x, y;
    scanf(" %d%d", &x, &y);
    ++x;
    ++y;
    char c = find_greatest(x, y);
    int ret = cnt[y][c-'a'] - cnt[x-1][c-'a'];
    printf("%d\n", ret);
  }
}

int main() {
  scanf(" %d%s%d", &N, S+1, &Q);
  init();
  solve();
  return 0;
}
