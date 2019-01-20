#include <cstdio>
#include <cstring>
const int MAXS = 5e5+5;
char s[MAXS];
int n;

int main() {
	scanf(" %s", s);
	n = strlen(s);
	int head = 0;
	while ((head < n) && (s[head] != '[')) ++head;
	while ((head < n) && (s[head] != ':')) ++head;
	int tail = n-1;
	while ((tail >=0) && (s[tail] != ']')) --tail;
	while ((tail >=0) && (s[tail] != ':')) --tail;
	if (head < tail) {
		int ret = 4;
		for (int i = head+1; i < tail; ++i) {
			if (s[i] == '|') ++ret;
		}
		printf("%d\n", ret);
	} else {
		puts("-1");
	}
	return 0;
}
