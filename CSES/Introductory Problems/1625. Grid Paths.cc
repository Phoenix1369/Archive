#include <cstdio>
const int K = 4;
const int N = 7;
const int N2 = N*N-1;
bool seen[N][N]{ };
char S[N2];
int ret;

struct State {
  int r, c;

  State operator + (const State& o) const {
    return {r+o.r, c+o.c};
  }

  bool in_range() const {
    return (0 <= r) && (r < N) && (0 <= c) && (c < N);
  }

  bool& visit() const {
    return seen[r][c];
  }

  bool open() const {
    return this->in_range() && !this->visit();
  }
};
// NESW
const char    D[K] = {'U', 'R', 'D', 'L'};
const State dir[K] = {{-1,0}, {0,+1}, {+1,0}, {0,-1}};

bool divide(const State& v, int k) {
  // Consider a candidate neighbour (v) in direction k from (u) to explore.
  // If orthogonal neighbours (p q) are both open,
  // and at least one of (x y z) in front of (v) is not,
  // then taking (v) necessarily splits the board.

  int cl = (k + K - 1) % K;
  int cr = (k + 1) % K;

  State p = v + dir[cl];
  State q = v + dir[cr];
  if (!p.open() || !q.open()) {
    return false;
  }

  State x = v + dir[k];
  State y = p + dir[k];
  State z = q + dir[k];
  return !(x.open() && y.open() && z.open());
}

void dfs(const State& u, int i) {
  bool A = (i == N2);
  bool B = (u.r == N-1) && (u.c == 0);
  if (A || B) {
    if (A && B) ++ret;
    return;
  }

  u.visit() = true;
  for (int k = 0; k < K; ++k) {
    if ((S[i] != '?') && (D[k] != S[i])) {
      continue;
    }
    State v = u + dir[k];
    if (!v.open() || divide(v, k)) {
      continue;
    }
    dfs(v, i+1);
  }
  u.visit() = false;
}

int main() {
  for (int i = 0; i < N2; ++i) {
    S[i] = getchar();
  }
  ret = 0;
  dfs({0, 0}, 0);
  printf("%d\n", ret);
  return 0;
}
