#include <cstdio>
#include <map>
#define x first
#define y second
std::map<int,int> cnt;
int a, n, T;
int best[2], prv, ret[2];

void assign(int a, int b)
{
	int P = 2*(a+b); P *= P;
	int S = a*b;
	if(!best[0] || (1LL*P*best[1] < 1LL*S*best[0]))
	{
		best[0] = P;
		best[1] = S;
		ret[0] = a;
		ret[1] = b;
	}
}

int main()
{
	scanf("%d", &T);
	for(int t = 1; t <= T; ++t)
	{
		scanf("%d", &n);
		cnt.clear();
		for(int i = 0; i < n; ++i)
		{
			scanf("%d", &a);
			++cnt[a];
		}
		best[0]=best[1]=prv=ret[0]=ret[1]=0;
		for(auto stk: cnt)
		{
			if(stk.y >= 4)
				assign(stk.x, stk.x);
			if(stk.y < 2) continue;
			if(prv > 0)
				assign(prv, stk.x);
			prv = stk.x;
		}
		for(int i = 0; i < 2; ++i)
		for(int j = 0; j < 2; ++j)
			printf("%d ", ret[i]);
		putchar('\n');
	}
	return 0;
}
