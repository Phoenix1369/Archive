#include <algorithm>
#include <cstdio>
typedef long long lld;
const int MAXN = 1E4+5;
int array[MAXN]{ };
int linkd[MAXN][2]{ }; // [value][ prev, next ]
int tempo[MAXN][2]{ };
int visit[MAXN]{ }; // [value]
int head, lhs, N, rhs;
lld Ans=0;

void pop_linked(int (&llist)[MAXN][2], const int& val)
{
	lhs = llist[val][0];
	rhs = llist[val][1];
	llist[lhs][1] = rhs;
	llist[rhs][0] = lhs;
}

int main()
{
	scanf("%d", &N);
	for(int i = 1; i <= N; ++i)
	{
		scanf("%d", &array[i]);
		linkd[array[i]-1][1] = array[i];
		linkd[array[i]+1][0] = array[i];
	}
	int M, mid;
	linkd[1][0] = -1;
	linkd[N][1] = -1;
	for(int L = 1, R; L <= N; ++L)
	{	// Fixed Left Bound [i..N]
		for(int i = 1; i <= N; ++i)
			for(int j = 0; j < 2; ++j)
				tempo[i][j] = linkd[i][j];
		if((N-L) & 1)
		{
			pop_linked(tempo, array[N]);
			R = N-1;
		}
		else
			R = N;
		M = array[L];
		mid = (R-L)/2; // Steps to Advance
		for(int i = L; i <= R; ++i)
			M = std::min(array[i], M);
		for(int k = 0; k < mid; ++k)
			M = tempo[M][1]; // Advance Pointer in O(N)
		Ans += 1LL*L*R*M;
		while((R -= 2) >= L)
		{
			int large=0, small=0;
			for(int k = 1; k <= 2; ++k)
			{
				if(array[R+k] <= M)
					++small;
				if(array[R+k] >= M)
					++large;
				pop_linked(tempo, array[R+k]);
			}
			if(small >= 2)
				M = tempo[M][1];
			if(large >= 2)
				M = tempo[M][0];
			Ans += 1LL*L*R*M;
		}
		pop_linked(linkd, array[L]);
		visit[array[L]] = true;
	}
	printf("%lld\n", Ans);
	return 0;
}