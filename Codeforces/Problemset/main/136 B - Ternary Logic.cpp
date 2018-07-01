#include <algorithm>
#include <cstdio>
const int K = 3;
const int LG3N = 20;
int  D[2][LG3N]{ };
unsigned ret=0U;
int A, L[2]{ };

int main()
{
	for(int i = 0; i < 2; ++i)
	{
		scanf("%d", &A);
		for(int n = A; n; n /= K)
			D[i][L[i]++] = n % K;
	}
	for(int i = std::max(L[0], L[1])-1; i >= 0; --i)
		ret = K*ret + (D[1][i]-D[0][i]+K) % K;
	printf("%u\n", ret);
	return 0;
}