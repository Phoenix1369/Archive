#include <cstdio>
#include <unordered_map>
#include <vector>
#define ALL(x) (x).begin(), (x).end()
using std::vector;
typedef long long lld;
int D, N, X;
lld ret;

struct Pair {
  lld L, R;

  bool operator < (const Pair& o) const {
    return (L != o.L) ? (L < o.L) : (R < o.R);
  }
};
std::unordered_map<lld, vector<Pair>> R;
vector<Pair> tmp;

lld sum(int x) { return 1LL * x * (x + 1) / 2; }

void merge_adjacent(vector<Pair>& B) {
  int sz = B.size();
  tmp.clear();
  tmp.reserve(sz);
  for (const Pair& cur: B) {
    if (tmp.empty() || (tmp.back().R < cur.L)) {
      tmp.push_back(cur);
    } else if (tmp.back().R < cur.R) {
      tmp.back().R = cur.R;
    }
  }
  B = move(tmp);
}

lld solve() {
  if (D == 0) {
    return (X == 0) ? 1 : (N + 1);
  }
  if (D < 0) {
    D *= -1;
    X *= -1;
  }
  R.clear();
  R.reserve(N+1);
  for (int k = 0; k <= N; ++k) {
    lld base = 1LL * k * X;
    lld offset = base / D;
    R[base % D].push_back({
      offset + sum(k-1),
      offset + sum(N-1) - sum(N-k-1)
    });
  }
  lld ret = 0LL;
  for (auto& itr: R) {
    auto& data = itr.second;
    std::sort(ALL(data));
    merge_adjacent(data);
    for (const Pair& cur: data) {
      ret += cur.R - cur.L + 1;
    }
  }
  return ret;
}

int main() {
  scanf(" %d%d%d", &N, &X, &D);
  printf("%lld\n", solve());
  return 0;
}
