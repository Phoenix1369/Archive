#include <cstdio>
const int MAXB = 64;
const int MAXF = 1e9;
const int MAXN = 1005;
int a[MAXN], b[MAXN];
int m, n;

bool f(double fuel)
{
	double w = m+fuel;
	for(int i = 0; i < n; ++i)
	{
		w -= w / a[i]; // Takeoff
		if(w < m) return false;
		w -= w / b[i+1]; // Landing
		if(w < m) return false;
	}
	return true;
}

void bs()
{
	double lo=0.0, hi=MAXF+1.0;
	for(int b = 0; b < MAXB; ++b)
	{
		double ce=(lo+hi)/2.0;
		if(f(ce))
			hi = ce;
		else
			lo = ce;
	}
	if(lo <= MAXF)
		printf("%.9f\n", lo);
	else
		puts("-1");
}

bool solve()
{
	double w = m;
	for(int i = n-1; i >= 0; --i)
	{	// Let u in {a,b}:	w+f = u*f <-> f = w/(u-1)
		if((a[i] == 1) || (b[i+1] == 1))
			return false;
		w += w / (b[i+1]-1);
		w += w / (a[i]-1);
	}
	printf("%.9f\n", w-m);
	return true;
}

int main()
{
	scanf(" %d%d", &n, &m);
	for(int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	for(int i = 0; i < n; ++i)
		scanf("%d", &b[i]);
	b[n] = b[0];
	// bs();
	if(!solve())
		puts("-1");
	return 0;
}
