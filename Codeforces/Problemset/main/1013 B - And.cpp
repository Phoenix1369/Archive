#include <cstdio>
const int MAXA = 1e5+5;
int cnt[MAXA]{ }, dnt[MAXA]{ };
int a, n, x;

int main()
{
	scanf(" %d%d", &n, &x);
	bool yes[3]{ };
	for(int i = 0; i < n; ++i)
	{
		scanf("%d", &a);
		if(cnt[a])
			yes[0] = true;
		if(dnt[a])
			yes[1] = true;
		int b = (a & x);
		if(cnt[b])
			yes[1] = true;
		if(dnt[b])
			yes[2] = true;
		++cnt[a];
		++dnt[b];
	}
	for(int i = 0; i < 3; ++i) if(yes[i])
		return printf("%d\n", i) & 0;
	puts("-1");
	return 0;
}
