#include <cstdio>
const int MAXC = 60;
char buff[MAXC]{ };
int n;

int main() {
	scanf("%d", &n);
	scanf(" %s", buff);
	int i = 0;
	int j = 1;
	while (i < n) {
		putchar(buff[i]);
		i += j;
		++j;
	}
	putchar('\n');
	return 0;
}
