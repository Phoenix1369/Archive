#include <cstdio>
int M, T, X, Y;

int f(int N, int E, int L)
{	// Phase: Un-Merge
	bool np = (N >= L);
	if(np) ++N;		// In 2nd Segment
	// Phase: Un-Erase
	int En = E+np*L;
	if(En <= N) ++N;	// Element of segment introduced before N
	// Phase: Un-Split
	if(N <= L)		// Traceback of interleaving index of N
		N = 2*N-1;
	else	N = 2*(N-L);
	return N;
}

int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf(" %d%d%d", &M, &X, &Y);
		int A = 1, B = 2;
		for(int i = 1; i*2 < M; ++i)
		{
			int E = (int)(1.0*(i+1)*X/Y) + 1;
			A = f(A, E, i+1);
			B = f(B, E, i+1);
		}
		printf("%d\n", A^B);
	}
	return 0;
}