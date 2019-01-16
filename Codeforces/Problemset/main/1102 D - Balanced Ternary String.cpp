#include <cstdio>
const int MAXN = 3e5+5;
char buff[MAXN], soln[MAXN];
int cnt[3]{ };
int n, t;

void assign(int i, int a, int b) {
	if (buff[i] != a+'0') return;
	if ((cnt[a] > t) && (cnt[b] < t)) {
		buff[i] = '\0';	// Flag as used
		soln[i] = b+'0';
		--cnt[a];
		++cnt[b];
	}
}

int main() {
	scanf("%d", &n);
	scanf(" %s", buff);
	for (int i = 0; i < n; ++i) {
		++cnt[buff[i]-'0'];
		soln[i] = buff[i];
	}
	soln[n] = '\0';
	t = n / 3;
	for (int i = 0; i < n; ++i) {
		assign(i, 1, 0);
		assign(i, 2, 0);
		assign(i, 2, 1);
	}	// Leading: (2 -> 1) (1 -> 0)
	for (int i = n-1; i >= 0; --i) {
		assign(i, 1, 2);
		assign(i, 0, 2);
		assign(i, 0, 1);
	}	// Trailing: (0 -> 1) (1 -> 2)
	puts(soln);
	return 0;
}
