#include <cstdio>
const int MAXS = 20;
const int MAXW = 3;
const char* W[] = {
  "Sunny", "Cloudy", "Rainy"
};
char S[MAXS];

int solve() {
  for (int i = 0; i < MAXW; ++i) {
    if (S[0] == W[i][0]) {
      return (i + 1) % MAXW;
    }
  }
  return 0;
}

int main() {
  scanf(" %s", S);
  puts(W[solve()]);
  return 0;
}
