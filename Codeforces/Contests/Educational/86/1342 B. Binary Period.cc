#include <cstdio>
#include <cstring>
const int MAXS = 205;
char S[MAXS];
char t[MAXS];
int N, T;

bool uniform() {
  for (int i = 0; i < N; ++i) {
    if (t[i] != t[0]) {
      return false;
    }
  }
  return true;
}

void solve() {
  scanf(" %s", t);
  N = strlen(t);
  if (uniform()) {
    strcpy(S, t);
    return;
  }
  char c = t[0];
  for (int i = 0; i < N; ++i) {
    S[2*i] = c;
    S[2*i+1] = c^1;
  }
  S[2*N] = '\0';
}

int main() {
  scanf("%d", &T);
  for (int t = 0; t < T; ++t) {
    solve();
    puts(S);
  }
  return 0;
}
