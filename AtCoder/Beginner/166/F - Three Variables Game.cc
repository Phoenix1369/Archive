#include <cstdio>
const int MAXN = 1e5+5;
const int MAXS = 5;
char  out[MAXN];
char    S[MAXN][MAXS];
int C[3];
int N;

bool check(int i, char c) {
  return (S[i][0] == c) || (S[i][1] == c);
}

bool solve() {
  int sum = C[0] + C[1] + C[2];
  if (sum == 0) {
    return false;
  }
  for (int i = 0; i < N; ++i) {
    int u = S[i][0] - 'A';
    int v = S[i][1] - 'A';
    if (!C[u] && !C[v]) {
      return false;
    }
    bool U = C[u];
    if (C[u] && C[v]) {
      int nxt = i+1;
      if ((nxt < N) && !check(nxt, S[i][1])) U = false;
    }
    if (U) {
      out[i] = S[i][1];
      --C[u];
      ++C[v];
    } else {
      out[i] = S[i][0];
      ++C[u];
      --C[v];
    }
  }
  return true;
}

int main() {
  scanf("%d", &N);
  for (int i = 0; i < 3; ++i) {
    scanf("%d", &C[i]);
  }
  for (int i = 0; i < N; ++i) {
    scanf(" %s", S[i]);
  }
  if (solve()) {
    puts("Yes");
    for (int i = 0; i < N; ++i) {
      putchar(out[i]);
      puts("");
    }
  } else {
    puts("No");
  }
  return 0;
}
