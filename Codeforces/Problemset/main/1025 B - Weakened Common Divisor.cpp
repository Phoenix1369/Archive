#include <cstdio>
#include <vector>
typedef std::vector<int> vin;
const int MAXN = 1.5e5+5;
int a[2][MAXN];
vin A, B;
int n;

vin factor(int m)
{
	vin fact;
	for(int i = 2; i*i <= m; ++i) if((m % i) == 0)
	{
		while((m % i) == 0) m /= i;
		fact.push_back(i);
	}
	if(m > 1)
		fact.push_back(m);
	return fact;
}

bool solve(int d)
{
	for(int i = 1; i < n; ++i)
		if((a[0][i] % d) && (a[1][i] % d))
			return false;
	printf("%d\n", d);
	return true;
}

int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
	for(int j = 0; j < 2; ++j)
		scanf(" %d", &a[j][i]);
	for(int i = 0; i < 2; ++i)
	for(int j: factor(a[i][0]))
		if(solve(j))
			return 0;
	puts("-1");
	return 0;
}
