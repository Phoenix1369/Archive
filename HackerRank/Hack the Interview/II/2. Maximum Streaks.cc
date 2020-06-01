#include <algorithm>
#include <cstdio>
int H, T, mh, mt;
char C;
int N;

int main() {
  scanf("%d", &N);
  H = T = mh = mt = 0;
  for (int i = 0; i < N; ++i) {
    scanf(" %c%*s", &C);
    if (C == 'H') {
      T = 0;
      ++H;
      mh = std::max(H, mh);
    } else {
      H = 0;
      ++T;
      mt = std::max(T, mt);
    }
  }
  printf("%d %d\n", mh, mt);
  return 0;
}
