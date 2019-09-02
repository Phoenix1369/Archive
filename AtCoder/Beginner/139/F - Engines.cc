#include <algorithm>
#include <cmath>
#include <cstdio>
const int MAXN = 205;
int N, N2;

struct Point {
  int X, Y;

  bool operator < (const Point& o) const {
    return atan2(Y, X) < atan2(o.Y, o.X);
  }

  Point& operator += (const Point& o) {
    X += o.X;
    Y += o.Y;
    return *this;
  }

  Point operator - (const Point& o) const {
    return {X - o.X, Y - o.Y};
  }

  double size() const {
    return std::hypot(X, Y);
  }
} P[MAXN];


int main() {
  scanf("%d", &N);
  for (int i = 0; i < N; ++i) {
    scanf(" %d%d", &P[i].X, &P[i].Y);
  }
  std::sort(P, P+N);
  for (int i = 0; i < N; ++i) {
    P[i+N] = P[i];
  }
  N2 = 2*N;
  for (int i = 1; i < N2; ++i) {
    P[i] += P[i-1];
  }
  double ret = 0.0;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      ret = std::max((P[i+j+1] - P[i]).size(), ret);
    }
  }
  printf("%.15f\n", ret);
  return 0;
}
