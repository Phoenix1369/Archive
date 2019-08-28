#include <cstdio>
#include <vector>
const int MAXN = 55;
int A[MAXN][MAXN];
int B[MAXN][MAXN]{ };
int M, N;

struct Pair {
  int X, Y;
};
std::vector<Pair> ret;

bool can_place(int i, int j) {
  for (int di = -1; di <= 0; ++di) {
    for (int dj = -1; dj <= 0; ++dj) {
      if (A[i + di][j + dj] == 0) {
        return false;
      }
    }
  }
  return true;
}

void place_sub(int i, int j) {
  for (int di = -1; di <= 0; ++di) {
    for (int dj = -1; dj <= 0; ++dj) {
      B[i + di][j + dj] = 1;
    }
  }
}

bool is_equal() {
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      if (B[i][j] != A[i][j]) {
        return false;
      }
    }
  }
  return true;
}

int main() {
  scanf(" %d%d", &N, &M);
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      scanf("%d", &A[i][j]);
    }
  }
  for (int i = 1; i < N; ++i) {
    for (int j = 1; j < M; ++j) {
      if (!can_place(i, j)) continue;
      place_sub(i, j);
      ret.emplace_back(Pair{i, j});
    }
  }
  if (is_equal()) {
    printf("%u\n", ret.size());
    for (auto p: ret) {
      printf("%d %d\n", p.X, p.Y);
    }
  } else {
    puts("-1");
  }
  return 0;
}
