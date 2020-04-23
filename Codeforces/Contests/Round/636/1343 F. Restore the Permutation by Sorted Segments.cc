#include <algorithm>
#include <bitset>
#include <cstdio>
#include <vector>
#define ALL(x) (x).begin(), (x).end()
const int MAXN = 205;
int K[MAXN], P[MAXN];
int N, T;

// Auxiliary
std::bitset<MAXN> S[MAXN];
std::vector<int> one;
int cnt[MAXN];
int low[MAXN];
int s;

// Copy
std::bitset<MAXN> Scpy[MAXN];
int cntcpy[MAXN];

void init() {
  one.clear();
  for (int i = 1; i <= N; ++i) {
    S[i].reset();
    cnt[i] = 0;
  }
}

void save() {
  for (int i = 1; i <= N; ++i) {
    cntcpy[i] = cnt[i];
    Scpy[i] = S[i];
  }
}

void find_single() {
  // At most two elements may appear once over all segments: p1 and pn
  for (int i = 1; i <= N; ++i) {
    if (cnt[i] == 1) {
      one.push_back(i);
    }
  }
}

void load() {
  low[0] = -1;
  for (int i = 1; i <= N; ++i) {
    cnt[i] = cntcpy[i];
    S[i] = Scpy[i];
    low[i] = 0;
  }
}

int find_segment(int cur) {
  for (int j = 1; j < N; ++j) {
    if (S[j].test(cur)) {
      return j;
    }
  }
  return 0;
}

bool is_first_slot(int idx) {
  return (idx == 2);
}

bool is_not_first(int elem) {
  return (std::find(ALL(one), elem) == one.end());
}

int find_next(int idx) {
/*
  Element (cur) appears once over all segments
  Find the segment (seg) containing it
    * cur is the rightmost element of seg
  Remove all other elements (x) from seg
    * Being in seg bounds their lowest valid index (low[x])
  Count of one element drops to 1 (pk)
    * A second element may have count of 1 (p1)
    * Break ties by low[x] and skip p1
  Handle p1 separately
    * Its count drops to 0 since there are (n-1) segments
*/
  int cur = P[idx];
  int seg = find_segment(cur);
  if (!seg) {
    return 0;
  }

  int best = 0;
  for (int x = 1; x <= N; ++x) {
    if (!S[seg].test(x)) {
      continue;
    }
    low[x] = std::max(idx - K[seg] + 1, low[x]);
    --cnt[x];
    if ((cnt[x] == 1) && (low[x] >= low[best]) && is_not_first(x)) {
      best = x;
    }
    S[seg].reset(x);
  }
  cnt[cur] = -1;
  if (!best && is_first_slot(idx)) {
    for (int x = 1; x <= N; ++x) {
      if ((cnt[x] == 0) && (low[x] >= low[best])) {
        best = x;
      }
    }
  }
  return best;
}

bool build(int last) {
  load();
  P[N] = last;
  for (int i = N; i >= 1; --i) {
    if (!P[i]) {
      return false;
    }
    P[i-1] = find_next(i);
  }
  return true;
}

void solve() {
  scanf("%d", &N);
  init();
  for (int i = 1; i < N; ++i) {
    scanf("%d", &K[i]);
    for (int j = 0; j < K[i]; ++j) {
      scanf("%d", &s);
      S[i].set(s);
      ++cnt[s];
    }
  }
  save();

  // Fix pn then try restoring remaining permutation
  find_single();
  for (int x: one) {
    if (build(x)) break;
  }
}

int main() {
  scanf("%d", &T);
  for (int t = 0; t < T; ++t) {
    solve();
    for (int i = 1; i <= N; ++i) {
      printf("%d ", P[i]);
    }
    putchar('\n');
  }
  return 0;
}
