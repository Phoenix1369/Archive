#include <cstdio>
int a, t;

int main() {
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		scanf(" %d%*d", &a);
		printf("%d %d\n", a, a*2);
	}
	return 0;
}
