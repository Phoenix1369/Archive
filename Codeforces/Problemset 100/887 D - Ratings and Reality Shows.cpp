#include <algorithm>
#include <cstdio>
typedef long long lld;
const int MAXN = 3E5+5;
lld  psum[MAXN]{ };
lld  qsum[MAXN]{ };
int  time[MAXN]{ };
int  type[MAXN]{ };
int a, b, c, d, len, N, q, start;

int main()
{
	scanf("%d%d%d%d%d%d%d", &N, &a, &b, &c, &d, &start, &len);
	psum[0] = qsum[0] = start; time[0] = -1;
	for(int i = 1; i <= N; ++i)
	{
		scanf("%d%d", &time[i], &type[i]);
		psum[i] = psum[i-1] + (type[i] ? a : -b);
		qsum[i] = qsum[i-1] + (type[i] ? c : -d);
	}
	int h=0, t=0; lld mn=start;
	qsum[N+1] = qsum[N]; time[N+1] = time[N]+len;
	while((h <= N) && (psum[h] >= 0))
	{
		if(h)	mn += (type[h] ? (a-c) : -(b-d));
		while((t <= N) && (time[t]-time[h] <= len))
		{
			mn = std::min(qsum[t]+psum[h]-qsum[h], mn);
			++t;
		}
		if(mn >= 0)
			return printf("%d\n", time[h]+1) & 0;
		++h;
	}
	puts("-1");
	return 0;
}