#include <cstdio>
constexpr int N = 8;
constexpr int N2 = N*2;
const char FREE = '.';
char A[N][N];
bool R[N]{ };
bool dl[N2]{ };
bool dr[N2]{ };
int ret;

void place(int r, int c, bool b) {
  R[r] = dl[r+c] = dr[r-c+N-1] = b;
}

void dfs(int c) {
  if (c == N) {
    ++ret;
    return;
  }
  for (int r = 0; r < N; ++r) {
    if (R[r] || dl[r+c] || dr[r-c+N-1]) continue;
    if (A[r][c] != FREE) continue;
    place(r, c, true);
    dfs(c+1);
    place(r, c, false);
  }
}

int main() {
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      A[i][j] = getchar();
    }
    scanf("\n");
  }
  ret = 0;
  dfs(0);
  printf("%d\n", ret);
  return 0;
}
