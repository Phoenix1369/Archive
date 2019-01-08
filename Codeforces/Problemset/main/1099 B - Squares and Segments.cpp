#include <cmath>
#include <cstdio>
int n;

int main() {
	scanf("%d", &n);
	int s = sqrt(n);
	int S = s*s;
	printf("%d\n", s+s+(S < n)+(S+s < n));
	return 0;
}
