#include <algorithm>
#include <cstdio>
#include <numeric>
const int N = 8;
int A[N], X[N], Y[N];

bool is_rect(int k)
{
	return	((X[A[k+3]]-X[A[k]]) == (X[A[k+1]]-X[A[k]])+(X[A[k+2]]-X[A[k]])) &&
		((Y[A[k+3]]-Y[A[k]]) == (Y[A[k+1]]-Y[A[k]])+(Y[A[k+2]]-Y[A[k]])) &&
		((Y[A[k+1]]-Y[A[k]])*(Y[A[k+2]]-Y[A[k]]) == (X[A[k]]-X[A[k+2]])*(X[A[k+1]]-X[A[k]]));
}

int main()
{
	for(int i = 0; i < N; ++i)
		scanf("%d%d", &X[i], &Y[i]);
	bool yes = false;
	std::iota(A, A+N, 0);
	do {
		if(	is_rect(0) && is_rect(4) &&
			((X[A[1]]-X[A[0]]) == (Y[A[2]]-Y[A[0]])) &&
			((Y[A[1]]-Y[A[0]]) == (X[A[0]]-X[A[2]])) )
		{
			yes = true;
			break;
		}
	} while(std::next_permutation(A, A+N));
	puts(yes ? "YES" : "NO");
	if(!yes) return 0;
	for(int i = 0; i < N; ++i)
		printf("%d%c", A[i]+1, ((i & 3) == 3) ? '\n' : ' ');
	return 0;
}