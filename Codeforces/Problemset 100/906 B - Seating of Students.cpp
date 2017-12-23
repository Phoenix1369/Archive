#include <cstdio>
#include <vector>
typedef std::vector<int> vin;
std::vector<vin> A;
int M, N, P;

int main()
{
	scanf("%d%d", &N, &M); P = N*M;
	if(P == 1) return puts("YES\n1"), 0;
	if(P <= 3) return puts("NO"), 0;
	if((N == 1) || (M == 1))
	{
		puts("YES");
		char C = (N == 1) ? ' ' : '\n';
		for(int i = 2; i <= P; i += 2)
			printf("%d%c", i, C);
		for(int i = 1; i <= P; i += 2)
			printf("%d%c", i, C);
		return	putchar('\n') & 0;
	}
	if(P <= 6) return puts("NO"), 0;
	if(P == 9) return puts("YES\n8 1 6\n3 5 7\n4 9 2"), 0;
	A.reserve(N+3);
	for(int i = 0; i <= N+2; ++i)
	{
		A.push_back(vin());
		A.back().reserve(M+3);
		for(int j = 0; j <= M+2; ++j)
			A.back().push_back(0);
	}
	for(int i = 1; i <= N; ++i)
	for(int j = 1; j <= M; ++j)
		A[i][j] = (i-1)*M+j;
	if(M >= 4)
	{	// Rotate Odd Rows by 2
		for(int i = 1; i <= N; i += 2)
		{
			A[i][M+1] = A[i][1];
			A[i][M+2] = A[i][2];
			for(int j = 1; j <= M; ++j)
				A[i][j] = A[i][j+2];
		}
		// Rotate Odd Columns by 1
		for(int j = 1; j <= M; j += 2)
		{
			A[0][j] = A[N][j];
			for(int i = N; i >= 1; --i)
				A[i][j] = A[i-1][j];
		}
	}
	else
	{	// Rotate Odd Columns by 2
		for(int j = 1; j <= M; j += 2)
		{
			A[N+1][j] = A[1][j];
			A[N+2][j] = A[2][j];
			for(int i = 1; i <= N; ++i)
				A[i][j] = A[i+2][j];
		}
		// Rotate Odd Rows by 1
		for(int i = 1; i <= N; i += 2)
		{
			A[i][0] = A[i][M];
			for(int j = M; j >= 1; --j)
				A[i][j] = A[i][j-1];
		}
	}
	puts("YES");
	for(int i = 1; i <= N; ++i)
	for(int j = 1; j <= M; ++j)
		printf("%d%c", A[i][j], (j==M)?'\n':' ');
	return 0;
}