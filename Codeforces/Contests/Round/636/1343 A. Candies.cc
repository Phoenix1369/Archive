#include <cmath>
#include <cstdio>
const int MAXK = 30;
int N, T;

void solve() {
  scanf("%d", &N);
  for (int k = 2; k < MAXK; ++k) {
    int val = (1 << k) - 1;
    if ((N % val) == 0) {
      printf("%d\n", N / val);
      break;
    }
  }
} 

int main() {
  scanf("%d", &T);
  for (int t = 0; t < T; ++t) {
    solve();
  }
  return 0;
}
