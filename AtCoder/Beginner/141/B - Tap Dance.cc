#include <cstdio>
#include <cstring>
const int MAXS = 105;
char S[MAXS];
int N;

bool solve() {
  N = strlen(S);
  for (int i = 0; i < N; ++i) {
    if (i & 1) {
      if (S[i] == 'R') {
        return false;
      }
    } else if (S[i] == 'L') {
      return false;
    }
  }
  return true;
}

int main() {
  scanf("%s", S);
  puts(solve() ? "Yes" : "No");
  return 0;
}
