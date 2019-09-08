#include <cstdio>
#include <unordered_set>
const int MAXA = 26;
const int MAXS = 4;
const int TWO = 2;
int cnt[MAXA]{ };
char S[MAXS + 5];

int main() {
  scanf("%s", S);
  int two = 0;
  for (int i = 0; i < MAXS; ++i) {
    int c = S[i] - 'A';
    ++cnt[c];
    if (cnt[c] == TWO) {
      ++two;
    } else if (cnt[c] > TWO) {
      --two;
    }
  }
  puts((two == TWO) ? "Yes" : "No");
  return 0;
}
