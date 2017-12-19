#include <cstdio>
typedef long long lld;
const int MAXN = 1E5+5;
int	G[MAXN]{ };
bool seen[MAXN]{ };
int M[2], N;

int main()
{
	scanf("%d", &N);
	for(int i = 1; i <= N; ++i)
		scanf("%d", &G[i]);
	lld ret=0LL; M[0]=M[1] = 0;
	for(int i = 1; i <= N; ++i) if(!seen[i])
	{	// Find Cycle Lengths
		int cur=i, len=0;
		while(!seen[cur])
		{
			seen[cur] = true;
			cur = G[cur];
			++len;
		}
		if(len >= M[0])
		{
			M[1] = M[0];
			M[0] = len;
		}
		else if(len > M[1])
			M[1] = len;
		ret += 1LL*len*len;
	}	// Merge: (a+b)^2 = a^2 + b^2 + 2ab
	ret += 2LL*M[0]*M[1];
	printf("%lld\n", ret);
	return 0;
}