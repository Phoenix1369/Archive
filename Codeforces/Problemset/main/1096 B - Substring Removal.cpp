#include <cstdio>
const int MAXN = 2e5+5;
const int MOD = 998244353;
char buff[MAXN]{ };
int n;

int main() {
	scanf("%d", &n);
	scanf(" %s", buff);
	int head = 0;
	int tail = n-1;
	while (buff[head] == buff[0]) ++head;
	while (buff[tail] == buff[n-1]) --tail;
	tail = n-1-tail;
	if (buff[0] == buff[n-1])
		printf("%d\n", 1LL*(head+1)*(tail+1) % MOD);
	else
		printf("%d\n", head + tail + 1);
	return 0;
}
