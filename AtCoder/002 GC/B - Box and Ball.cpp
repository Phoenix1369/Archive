#include <cstdio>
const int MAXN = 1E5+5;
int   cnt[MAXN]{ };
bool  red[MAXN]{ };
int ans=0, M, N, x, y;

int main()
{
	scanf(" %d%d", &N, &M);
	for(int i = 1; i <= N; ++i)
		cnt[i] = 1;
	red[1] = true;
	for(int i = 0; i < M; ++i)
	{
		scanf(" %d%d", &x, &y);
		red[y] |= red[x];
		++cnt[y];
		red[x] &= --cnt[x];
	}
	for(int i = 1; i <= N; ++i)
		if(red[i]) ++ans;
	printf("%d\n", ans);
	return 0;
}