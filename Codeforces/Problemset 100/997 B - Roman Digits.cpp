#include <cstdio>
const int MAXD = 50;
const int MAXN = 1E4+5;
const int SOLN[] = { 0, 4, 10, 20, 35, 56, 83, 116, 155, 198, 244, 292 };
typedef long long lld;
int N;

int brute_force(int n)
{
	int cnt=0;
	bool seen[MAXD*MAXN]{ };
	for(int a = 0; a <= n; ++a)
	for(int b = 0; b <= n-a; ++b)
	for(int c = 0; c <= n-a-b; ++c)
	{
		int d = n-a-b-c;
		int v = a + 5*b + 10*c + 50*d;
		if(!seen[v])
		{
			seen[v] = true;
			++cnt;
		}
	}
	return cnt;
}

void driver()
{
	int prv=0, res;
	for(int i = 1; i <= MAXN; ++i)
	{
		res = brute_force(i);
		printf("%3d: %5d | diff=%d\n", i, res, res-prv);
		prv = res;
	}
}

int main()
{
	scanf("%d", &N);
	if(N <= 11)
		printf("%d\n", SOLN[N]);
	else
		printf("%lld\n", SOLN[11] + 49LL*(N-11));
    return 0;
}