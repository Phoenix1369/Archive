#include <cstdio>
#include <map>
#include <vector>
typedef long long lld;
typedef std::vector<int> vin;
const int MAXN = 1e5+5;
enum Dir { PREV=0, NEXT=1 };
int P[MAXN];
int one[MAXN][2]; // 1st Greater [Prev, Next]
int two[MAXN][2]; // 2nd Greater [Prev, Next]
std::map<int,int> SS;
vin S;
int N;

void init() {
  int val[] = { 0, N+1 };
  for (int i = 1; i <= N; ++i) {
    for (int j = 0; j < 2; ++j) {
      one[i][j] = two[i][j] = val[j];
    }
  }
}

void one_greater(Dir d, int i) {
  while (!S.empty()) {
    int k = S.back();
    if (P[k] > P[i]) break;
    one[k][d] = i;
    SS[P[k]] = k;
    S.pop_back();
  }
}

void two_greater(Dir d, int i) {
  while (!SS.empty()) {
    int k = SS.begin()->first;
    if (k > P[i]) break;
    two[SS.at(k)][d] = i;
    SS.erase(k);
  }
}

void next_greater() {
  S.clear();
  SS.clear();
  for (int i = 1; i <= N; ++i) {
    two_greater(NEXT, i);
    one_greater(NEXT, i);
    S.push_back(i);
  }
}

void prev_greater() {
  S.clear();
  SS.clear();
  for (int i = N; i >= 1; --i) {
    two_greater(PREV, i);
    one_greater(PREV, i);
    S.push_back(i);
  }
}

lld solve() {
  lld res = 0LL;
  for (int i = 1; i <= N; ++i) {
    res += 1LL * P[i] * (two[i][NEXT] - one[i][NEXT]) * (i - one[i][PREV]);
    res += 1LL * P[i] * (one[i][NEXT] - i) * (one[i][PREV] - two[i][PREV]);
  }
  return res;
}

int main() {
  scanf("%d", &N);
  for (int i = 1; i <= N; ++i) {
    scanf("%d", &P[i]);
  }
  init();
  next_greater();
  prev_greater();
  printf("%lld\n", solve());
  return 0;
}
