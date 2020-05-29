#include <algorithm>
#include <cstdio>
const int MAXN = 1e5+5;
char  S[MAXN];
int out[MAXN];
int M, N;
int K;

// Greedily take largest possible steps from N -> 0
// Range [head, tail) are Game Over squares

void display() {
  for (int i = 0; i < K; ++i) {
    printf("%d ", out[i]);
  }
  putchar('\n');
}

bool solve() {
  M = std::min(N, M);
  K = 0;
  
  int head = N;
  int tail = N;
  while (tail > 0) {
    int src = tail - std::min(M, tail);
    auto is_valid = [](char c) { return (c == '0'); };
    auto itr = std::find_if(S+src, S+head, is_valid);
    
    int next = itr - S;
    if (next == head) {
      return false;
    }
    
    head = src;
    out[K++] = (tail - next);
    tail = next;
  }
  std::reverse(out, out+K);
  return true;
}

int main() {
  scanf(" %d%d%s", &N, &M, S);
  if (solve()) {
    display();
  } else {
    puts("-1");
  }
  return 0;
}
