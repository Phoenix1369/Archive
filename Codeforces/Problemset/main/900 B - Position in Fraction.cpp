#include <cstdio>
int A, B, C;

int main()
{
	scanf(" %d%d%d", &A, &B, &C);
	for(int k = 1; k <= B; ++k)
	{
		int q = A*10 / B;
		if(q == C) return printf("%d\n", k) & 0;
		A = A*10 - B*q;
	}
	puts("-1");
	return 0;
}