#include <algorithm>
#include <cstdio>
#include <vector>
#define ALL(x) (x).begin(), (x).end()
typedef long long lld;
typedef std::vector<int> vin;
const int MAXN = 1e5+5;
int A[MAXN];
int N, T;

vin I;
int C;

struct BinaryIndexedTree {
  int data[MAXN];

  void add(int x, int val) {
    for (int i = x; i <= C; i += i & -i) {
      data[i] += val;
    }
  }

  void clr() {
    for (int i = 0; i <= C; ++i) {
      data[i] = 0;
    }
  }

  int get(int x) {
    int sum = 0;
    for (int i = x; i >= 1; i -= i & -i) {
      sum += data[i];
    }
    return sum;
  }
} bit;

void compress() {
  // Coordinate compression
  I.clear();
  I.reserve(N);
  for (int i = 1; i <= N; ++i) {
    I.push_back(A[i]);
  }
  std::sort(ALL(I));
  I.erase(std::unique(ALL(I)), I.end());
  C = I.size();
  for (int i = 1; i <= N; ++i) {
    A[i] = std::upper_bound(ALL(I), A[i]) - I.begin();
  }
}

lld f(lld x) {
  // Subarrays with inversions <= x
  bit.clr();
  lld res = 0;
  lld cnt = 0;
  int head = 1;
  for (int tail = 1; tail <= N; ++tail) {
    bit.add(A[tail], +1);
    cnt += (tail - head + 1) - bit.get(A[tail]);
    while (cnt > x) {
      cnt -= bit.get(A[head] - 1);
      bit.add(A[head], -1);
      ++head;
    }
    res += tail - head + 1;
  }
  return res;
}

lld solve() {
  lld K = 1LL * N * (N - 1) / 2;  // Inversions
  lld S = 1LL * N * (N + 1) / 2;  // Subarrays
  lld M = (S + 1) / 2;
  compress();
  
  lld lo = 0;
  lld hi = K;
  while (lo < hi) {
    lld x = (lo + hi) / 2;
    if (f(x) >= M) {
      hi = x;
    } else {
      lo = x + 1;
    }
  }
  return lo;
}

int main() {
  scanf("%d", &T);
  for (int t = 0; t < T; ++t) {
    scanf("%d", &N);
    for (int i = 1; i <= N; ++i) {
      scanf("%d", &A[i]);
    }
    printf("%lld\n", solve());
  }
  return 0;
}
