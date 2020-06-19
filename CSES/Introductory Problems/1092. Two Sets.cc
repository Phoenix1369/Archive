#include <cstdio>
typedef long long lld;
int n;
lld s;

lld sum(int x) { return 1LL * x * (x+1) / 2; }

void display(int a, int b) {
  for (int i = a; i <= b; ++i) {
    printf("%d ", i);
  }
}

void solve() {
  int m = (n+1) / 2;
  int q = n / 4;
  int end = m + q;
  
  int A = end - q;
  printf("%d\n", A);
  display(q+1, end);
  putchar('\n');
  
  int B = n - A;
  printf("%d\n", B);
  display(1, q);
  display(end+1, n);
  putchar('\n');
}

int main() {
  scanf("%d", &n);
  s = sum(n);
  if (s & 1) {
    puts("NO");
  } else {
    puts("YES");
    solve();
  }
  return 0;
}
