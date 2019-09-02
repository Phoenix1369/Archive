#include <cstdio>
#include <unordered_set>
const int MAXN = 1005;
int A[MAXN][MAXN];
int dex[MAXN];
int P[MAXN];
int N;
std::unordered_set<int> cur, nxt;

void init() {
  cur.clear();
  nxt.clear();
  for (int i = 1; i <= N; ++i) {
    dex[i] = 1;
  }
}

void push_next(int k) {
  if (dex[k] >= N) return;
  P[k] = A[k][dex[k]];
  if ((k == P[P[k]]) &&
      !nxt.count(k) &&
      !nxt.count(P[k])) {
    nxt.insert(k);
  }
}

int solve() {
  for (int i = 1; i <= N; ++i) push_next(i);
  cur = std::move(nxt);
  nxt.reserve(cur.size());

  int ret = 0;
  while (!cur.empty()) {
    for (auto a: cur) {
      int b = P[a];
      ++dex[a];
      ++dex[b];
      push_next(a);
      push_next(b);
    }
    cur = std::move(nxt);
    nxt.reserve(cur.size());
    ++ret;
  }
  for (int i = 1; i <= N; ++i) {
    if (dex[i] != N) {
      return -1;
    }
  }
  return ret;
}

int main() {
  scanf("%d", &N);
  init();
  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j < N; ++j) {
      scanf("%d", &A[i][j]);
    }
  }
  printf("%d\n", solve());
  return 0;
}
