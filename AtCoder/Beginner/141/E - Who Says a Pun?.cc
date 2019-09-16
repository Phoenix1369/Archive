#include <cstdio>
#include <unordered_map>
#include <vector>
const int HASH = 131;
const int MAXN = 5005;
const int MOD = 1e9+7;
char S[MAXN];
int H[MAXN];
int N, size;

std::unordered_map<int, std::vector<int>> D;

bool compare(int a, int b) {
  for (int k = 0; k < size; ++k) {
    if (S[a-k] != S[b-k]) return false;
  }
  return true;
}

bool matches(int sum, int cur) {
  for (int pos: D.at(sum)) {
    if (pos + size > cur) break;
    if (compare(pos, cur)) {
      return true;
    }
  }
  return false;
}

bool find() {
  D.clear();
  D.reserve(N);

  int sum = 0;
  for (int i = 0; i < N; ++i) {
    sum = (1LL * HASH * sum + S[i]) % MOD;
    if (i >= size) {
      int old = 1LL * H[size] * S[i-size] % MOD;
      sum = (sum - old + MOD) % MOD;
    }
    if (i+1 >= size) {
      if (D.count(sum) && matches(sum, i)) {
        return true;
      }
      D[sum].push_back(i);
    }
  }
  return false;
}

void init() {
  H[0] = 1;
  for (int i = 1; i <= N; ++i) {
    H[i] = 1LL * H[i-1] * HASH % MOD;
  }
}

int solve() {
  int lo = 0;
  int hi = N/2;
  while (lo < hi) {
    size = (lo + hi + 1) / 2;
    if (find()) {
      lo = size;
    } else {
      hi = size-1;
    }
  }
  return lo;
}

int main() {
  scanf(" %d%s", &N, S);
  init();
  printf("%d\n", solve());
  return 0;
}
