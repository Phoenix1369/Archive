#include <cstdio>
const int MAXN = 707;
bool dpl[MAXN][MAXN]{ };
bool dpr[MAXN][MAXN]{ };
bool   g[MAXN][MAXN]{ };
int a[MAXN];
int n;

template <typename T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	for(int i = 1; i <= n; ++i)
	for(int j = i; j <= n; ++j)
		g[i][j] = (gcd(a[i], a[j]) > 1);
	for(int i = 1; i <= n; ++i)
		g[0][i] = g[i][n+1] = true;
	for(int i = 1; i <= n; ++i)
	{	// Singleton
		dpl[i][i] = g[i][i+1];
		dpr[i][i] = g[i-1][i];
	}
	for(int k = 1; k < n; ++k)
	for(int i = 1; i+k <= n; ++i)
	{
		int j = i+k;
		dpl[i][j] = dpr[i][j] = false;
		for(int r = i; r <= j; ++r)
		{
			bool res = true;
			if(i < r) res &= dpl[i][r-1];
			if(r < j) res &= dpr[r+1][j];
			if(g[r][j+1])
				dpl[i][j] |= res;
			if(g[i-1][r])
				dpr[i][j] |= res;
		}
	}
	puts(dpl[1][n] ? "Yes" : "No");
	return 0;
}
