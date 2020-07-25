// UVa 10261 - Ferry Loading
#include <algorithm>
#include <iostream>
#include <vector>
#define ALL(x) (x).begin(), (x).end()
const int MAXN = 205;
int K, N;

template <typename T>
using vec = std::vector<T>;

vec<vec<bool>> dp;
vec<vec<bool>> pd;
vec<int> A;
vec<int> P;

vec<bool> ret;
int ans, val;

void input() {
  // Ferry
  std::cin >> K;
  K *= 100;

  // Cars
  A.clear();
  A.push_back(0);
  while (true) {
    int car;
    std::cin >> car;
    if (!car) {
      break;
    }
    A.push_back(car);
  }
  if (A.size() > MAXN) {
    A.resize(MAXN);
  }
  N = A.size();
}

void prefix() {
  P.assign(N, 0);
  for (int i = 1; i < N; ++i) {
    P[i] = P[i-1] + A[i];
  }
}

void solve() {
  dp.assign(N, vec<bool>(K+1, false));
  pd.assign(N, vec<bool>(K+1, false));

  dp[0][0] = true;
  for (int i = 1; i < N; ++i) {
    for (int j = 0; j <= K; ++j) {
      if (P[i] - j <= K) {
        bool diff = dp[i-1][j];
        if (diff) {
          dp[i][j] = true;
          pd[i][j] = false;
        } else if (j >= A[i]) {
          bool same = dp[i-1][j-A[i]];
          if (same) {
            dp[i][j] = true;
            pd[i][j] = true;
          }
        }
      }
    }
  }
}

void read() {
  for (int i = N-1; i >= 0; --i) {
    for (int j = K; j >= 0; --j) {
      if (dp[i][j]) {
        ans = i;
        val = j;
        return;
      }
    }
  }
}

void build() {
  int rem = val;
  ret.clear();
  for (int i = ans; i >= 1; --i) {
    bool cur = false;
    if (pd[i][rem]) {
      rem -= A[i];
    } else {
      cur = true;
    }
    ret.push_back(cur);
  }
  std::reverse(ALL(ret));
}

void output() {
  std::cout << ans << '\n';
  for (bool car: ret) {
    std::cout << (car ? "port" : "starboard") << '\n';
  }
}

void fastio() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
}

int main() {
  fastio();

  int t;
  std::cin >> t;
  while (t--) {
    input();
    prefix();

    solve();
    read();

    build();
    output();

    if (t) {
      std::cout << '\n';
    }
  }
  return 0;
}
