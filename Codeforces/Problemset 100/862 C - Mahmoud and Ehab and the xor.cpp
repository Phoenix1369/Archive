#include <cstdio>
int N, X;

int xor_sum(int K, int M)
{
	return (M==0) ? K : (M==1) ? 1 : (M==2) ? (K+1) : 0;
}

int main()
{
	scanf(" %d%d", &N, &X);
	if(!X && (N == 2))
		return puts("NO"), 0;
	puts("YES");
	if(N == 1)
		return printf("%d\n", X) & 0;
	else if(N == 2)
		return printf("0 %d\n", X) & 0;
	for(int i = 1; i <= N-3; ++i)
		printf("%d ", i);
	int S = xor_sum(N-3, (N-3) & 3);
	if(S == X)
		printf("%d %d %d\n", (1<<17), (1<<18), (1<<17)^(1<<18));
	else
		printf("0 %d %d\n", (1<<17), (1<<17)^S^X);
	return 0;
}
