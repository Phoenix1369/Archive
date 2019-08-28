#include <cstdio>
const int MAXN = 5e5+5;
const int SQTN = 707;
int A[MAXN]{ };
int cache[SQTN][SQTN]{ };
int T, X, Y;
int Q;

int main() {
  scanf("%d", &Q);
  for (int q = 0; q < Q; ++q) {
    scanf(" %d%d%d", &T, &X, &Y);
    switch (T) {
    case 1:
      A[X] += Y;
      for (int i = 1; i < SQTN; ++i) {
        cache[i][X % i] += Y;
      }
      break;
    case 2:
      if (X >= SQTN) {
        int ret = 0;
        for (int i = 0;; ++i) {
          int pos = i*X + Y;
          if (pos >= MAXN) break;
          ret += A[pos];
        }
        printf("%d\n", ret);
      } else {
        printf("%d\n", cache[X][Y]);
      }
      break;
    }
  }
  return 0;
}
