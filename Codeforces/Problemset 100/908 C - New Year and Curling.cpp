#include <algorithm>
#include <cstdio>
#include <cmath>
#define SQR(x) ((x)*(x))
const int MAXN = 1005;
int	X[MAXN];
double	Y[MAXN];
int N, R;

int main()
{
	scanf(" %d%d", &N, &R);
	for(int i = 0; i < N; ++i)
	{
		scanf("%d", &X[i]); Y[i] = R;
		for(int j = 0; j < i; ++j) if(std::abs(X[i]-X[j]) <= R*2)
			Y[i] = std::max(Y[j]+sqrt(SQR(R*2)-SQR(X[i]-X[j])), Y[i]);
		printf("%.9f ", Y[i]);
	}
	putchar('\n');
	return 0;
}