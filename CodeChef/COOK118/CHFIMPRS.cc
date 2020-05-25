#include <cstdio>
#include <unordered_map>
const int MAXN = 305;
std::unordered_map<int, int> cnt;
int B[MAXN][MAXN];
int A, M, N, T;

bool solve() {
  int odd = 0;
  for (const auto& itr: cnt) {
    if (itr.second & 1) ++odd;
  }
  return (M & 1) ? (odd <= N) : (odd == 0);
}

void arrange() {
  int odd = 0;
  int evr = 0;
  int evc = 0;
  int Mh = M / 2;
  for (const auto& itr: cnt) {
    int key = itr.first;
    int val = itr.second;

    // Odd column
    if (val & 1) {
      B[odd++][Mh] = key;
      --val;
    }
    val /= 2;

    // Even pairing
    while (val && (evr < N)) {
      if (evc >= Mh) {
        if (++evr >= N) break;
        evc = 0;
      }
      B[evr][evc] = key;
      B[evr][M-evc-1] = key;
      ++evc;
      --val;
    }

    // Even column
    while (val) {
      B[odd++][Mh] = key;
      B[odd++][Mh] = key;
      --val;
    }
  }
}

void display() {
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      printf("%d ", B[i][j]);
    }
    putchar('\n');
  }
}

void echo() {
  for (const auto& itr: cnt) {
    for (int i = 0; i < itr.second; ++i) {
      printf("%d\n", itr.first);
    }
  }
}

int main() {
  scanf("%d", &T);
  for (int t = 0; t < T; ++t) {
    scanf(" %d%d", &N, &M);
    cnt.clear();
    cnt.reserve(N * M);
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < M; ++j) {
        scanf("%d", &A);
        ++cnt[A];
      }
    }
    if (solve()) {
      if (M > 1) {
        arrange();
        display();
      } else {
        echo();
      }
    } else {
      puts("-1");
    }
  }
  return 0;
}
