#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
typedef std::vector<int> vin;
const int HASH = 131;
const int MAXS = 2e6+5;
const int MOD = 1e9+7;
const int NOPE = -1;
vin G[MAXS]; // Matching T
char s[MAXS];
char t[MAXS];
int deg[MAXS]; // In-degree
int lvl[MAXS]; // Distance
int N, S, T;
vin pos;

void kr() {
  // Karp-Rabin
  int B = 1;
  int P = 0;
  for (int i = 0; i < T; ++i) {
    P = (1LL * HASH * P % MOD + t[i]) % MOD;
    B = 1LL * HASH * B % MOD;
  }
  int Q = 0;
  for (int i = 0; i < N; ++i) {
    Q = (1LL * HASH * Q % MOD + s[i]) % MOD;
    if (i >= T) {
      Q = (Q - 1LL * B * s[i-T] % MOD + MOD) % MOD;
    }
    if (P == Q) {
      pos.push_back(i-T+1);
    }
  }
}

void repeat() {
  // Concatenate S with itself
  N = S;
  int st = S + T;
  while (N < st) {
    for (int i = 0; i < S; ++i, ++N) {
      s[N] = s[i];
    }
    s[N] = '\0';
  }
}

int solve() {
  for (int u: pos) {
    int v = (u + T) % S;
    G[u].push_back(v);
    ++deg[v];
  }
  std::queue<int> Q;
  for (int i = 0; i < N; ++i) {
    if (!deg[i]) {
      lvl[i] = 0;
      Q.push(i);
    } else {
      lvl[i] = NOPE;
    }
  }
  while (!Q.empty()) {
    int cur = Q.front();
    Q.pop();
    for (int nxt: G[cur]) {
      if (!--deg[nxt]) {
        lvl[nxt] = lvl[cur] + 1;
        Q.push(nxt);
      }
    }
  }
  int ret = 0;
  for (int i = 0; i < N; ++i) {
    if (lvl[i] == NOPE) {
      return NOPE;
    }
    ret = std::max(lvl[i], ret);
  }
  return ret;
}

int main() {
  scanf(" %s%s", s, t);
  S = strlen(s);
  T = strlen(t);
  repeat();
  kr();
  printf("%d\n", solve());
  return 0;
}
