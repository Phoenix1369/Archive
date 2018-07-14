#include <algorithm>
#include <cstdio>
const int MAXN = 1005;
int A[MAXN]{ };
int N;

bool is_sorted()
{
	for(int i = 1; i < N; ++i)
		if(A[i-1] > A[i])
			return false;
	return true;
}

int solve()
{
	for(int i = 1; i < N; ++i) if(A[i-1] > A[i])
	{
		for(int j = i; j < N; ++j)
		{
			std::swap(A[i-1], A[j]);
			if(is_sorted())
				return 1;
			std::swap(A[i-1], A[j]);
		}
		return -1;
	}
	return 0;
}

int main()
{
	scanf("%d", &N);
	for(int i = 0; i < N; ++i)
		scanf("%d", &A[i]);
	printf("%d\n", solve());
	return 0;
}
