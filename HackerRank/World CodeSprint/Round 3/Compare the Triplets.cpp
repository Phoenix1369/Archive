#include <cstdio>
int A[2][3], P[2]{ };

int main()
{
	for(int i = 0; i < 2; ++i)
	for(int j = 0; j < 3; ++j)
		scanf("%d", &A[i][j]);
	for(int i = 0; i < 3; ++i)
		if(A[0][i] != A[1][i])
			++P[A[0][i] < A[1][i]];
	printf("%d %d\n", P[0], P[1]);
	return 0;
}
