#include <algorithm>
#include <cstdio>
const int MAXA = 26;
const int MAXN = 55;
const int MAXO = 2505;
char s[MAXN], t[MAXN];
int cnt[MAXA]{ }, dnt[MAXA]{ }, out[MAXO];
int n, ret=0;

int main()
{
	scanf(" %d%s%s", &n, s, t);
	for(int i = 0; i < n; ++i)
		++cnt[s[i]-'a'];
	for(int i = 0; i < n; ++i)
		++dnt[t[i]-'a'];
	for(int i = 0; i < MAXA; ++i)
		if(cnt[i] != dnt[i])
			return puts("-1"), 0;
	for(int i = 0; i < n; ++i) if(s[i] != t[i])
	{
		int c = i+1;
		while(s[c] != t[i]) ++c;
		for(int j = c-1; j >= i; --j)
		{
			std::swap(s[j], s[j+1]);
			out[ret++] = j+1;
		}
	}
	printf("%d\n", ret);
	for(int i = 0; i < ret; ++i)
		printf("%d ", out[i]);
	putchar('\n');
	return 0;
}
