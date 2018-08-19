#include <algorithm>
#include <cstdio>
#include <cstring>
const int MAXN = 1005;
char s[MAXN], t[MAXN];
int eq[MAXN]{ };
int m, n, q;

int main()
{
	scanf(" %d%d%d", &n, &m, &q);
	scanf(" %s%s", s+1, t);
	for(int i = 1; i <= n; ++i)
	{
		char c = s[i+m];
		s[i+m] = '\0';
		eq[i] = eq[i-1];
		if(strcmp(s+i, t) == 0)
			++eq[i];
		s[i+m] = c;
	}
	for(int i = 0; i < q; ++i)
	{
		int l, r;
		scanf(" %d%d", &l, &r);
		r = std::max(l-1, r-m+1);
		printf("%d\n", eq[r]-eq[l-1]);
	}
	return 0;
}

