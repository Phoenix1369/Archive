#include <algorithm>
#include <cstdio>
int A, N, R, T;
 
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf(" %d%d", &N, &R);
		int lo=0, hi=1E9+1;
		bool good = true;
		for(int i = 0; i < N; ++i)
		{
			scanf("%d", &A);
			good &= (lo < A) && (A < hi);
			if(R >= A) lo = std::max(A, lo);
			if(R <= A) hi = std::min(A, hi);
		}
		puts(good ? "YES" : "NO");
	}
	return 0;
}
