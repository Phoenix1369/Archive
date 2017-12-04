#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>
const int MAXN = 1E5+5;
int  A[3][MAXN]{ };
int N[3], ptr[3], sum[3]{ };

int main()
{
	for(int i = 0; i < 3; ++i)
		scanf("%d", &N[i]);
	for(int i = 0; i < 3; ++i)
	for(int j = 0; j < N[i]; ++j)
	{
		scanf("%d", &A[i][j]);
		sum[i] += A[i][j];
	}
	ptr[0]=ptr[1]=ptr[2]=0;
	while((sum[0] != sum[1]) || (sum[1] != sum[2]))
	{	// Greedy Reduction
		int cur = std::min(sum[0], std::min(sum[1], sum[2]));
		for(int i = 0; i < 3; ++i)
			while((ptr[i] < N[i]) && (sum[i] > cur))
				sum[i] -= A[i][ptr[i]++];
	}
	printf("%d\n", sum[0]);
	return 0;
}