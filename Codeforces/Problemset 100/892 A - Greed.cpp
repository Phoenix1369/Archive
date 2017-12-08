#include <cstdio>
typedef long long lld;
int a, b[2], N;
lld sum=0LL;

int main()
{
	scanf("%d", &N);
	for(int i = 0; i < N; ++i)
	{
		scanf("%d", &a);
		sum += a;
	}
	b[0] = b[1] = -1;
	for(int i = 0; i < N; ++i)
	{
		scanf("%d", &a);
		if(a >= b[1])
		{
			b[0] = b[1];
			b[1] = a;
		}
		else if(a > b[0])
			b[0] = a;
	}
	puts((sum <= b[0]+b[1]) ? "YES" : "NO");
	return 0;
}