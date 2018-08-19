#include <cstdio>
const int MAXA = 26;
const int MAXN = 1e5+5;
int cnt[MAXA]{ };
char s[MAXN]{ };
int n;

int main()
{
	scanf(" %d%s", &n, s);
	for(int i = 0; i < n; ++i)
		if(++cnt[s[i]-'a'] >= 2)
			return puts("Yes"), 0;
	puts((n == 1) ? "Yes" : "No");
	return 0;
}
