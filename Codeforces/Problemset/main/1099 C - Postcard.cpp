#include <cstdio>
#include <cstring>
enum { CANE = '?', SNOW = '*' };
const int MAXS = 205;
char s[MAXS];
int spec[2]{ };
int k;

int main() {
	scanf(" %s", s);
	scanf("%d", &k);
	int cnt = 0;
	int len = strlen(s);
	for (int i = 0; i < len; ++i) {
		if (s[i] == CANE) {
			++spec[0];
		} else if (s[i] == SNOW) {
			++spec[1];
		} else {
			++cnt;
		}
	}
	if (((cnt < k) && spec[1]) || (cnt == k)) {
		for (int i = 0; i < len; ++i) {
			if (s[i] == SNOW) {
				while (cnt < k) {
					putchar(s[i-1]);
					++cnt;
				}
			} else if (s[i] != CANE) {
				putchar(s[i]);
			}
		}
		putchar('\n');
	} else if ((cnt > k) && (cnt-spec[0]-spec[1] <= k)) {
		for (int i = 0; i < len; ++i) {
			if ((s[i+1] == CANE) || (s[i+1] == SNOW)) {
				if (cnt > k) {
					--cnt;
				} else {
					putchar(s[i]);
				}
				++i;
			} else {
				putchar(s[i]);
			}
		}
		putchar('\n');
	} else {
		puts("Impossible");
	}
	return 0;
}
