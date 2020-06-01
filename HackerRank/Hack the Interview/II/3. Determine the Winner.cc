#include <cstdio>
char S;
int N;

struct Card {
  char s;
  int n;
  
  int compare(const Card& o) const {
    bool ls = (s == S);
    bool rs = (o.s == S);
    if (ls != rs) {
      return (ls) ? -1 : +1;
    }
    if (n != o.n) {
      return (n > o.n) ? -1 : +1;
    }
    return 0;
  }
  
  void read() {
    scanf(" %c%d", &s, &n);
  }
};
Card A;
Card B;

int main() {
  scanf(" %c%d", &S, &N);
  for (int i = 0; i < N; ++i) {
    A.read();
    B.read();
    int cmp = A.compare(B);
    if (cmp < 0) {
      puts("Player 1 wins");
    } else if (cmp > 0) {
      puts("Player 2 wins");
    } else {
      puts("Draw");
    }
  }
  return 0;
}
