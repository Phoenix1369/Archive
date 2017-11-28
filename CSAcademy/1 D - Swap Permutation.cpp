#include <algorithm>
#include <cstdio>
#include <numeric>
const int MAXN = 1E5+5;
int array[MAXN]{ };
int  part[MAXN]{ };
int K, M, N, nope=-1;

int main()
{
	scanf(" %d%d%d", &N, &M, &K);
	std::iota(array+1, array+N+1, 1);
	for(int i = 1; i <= M; ++i)
	{
		int u, v;
		scanf(" %d%d", &u, &v);
		if(array[u] == 1 || array[v] == 1)
		{
			if((array[u] == 1) && !part[array[v]])
				part[array[v]] = i;
			if((array[v] == 1) && !part[array[u]])
				part[array[u]] = i;
		}
		else if(nope == -1)
			nope = i;
		std::swap(array[u], array[v]);
	}
	if(array[K] != 1) // Swapped in Other
		printf("%d\n", part[array[K]]);
	else	// Case: Erase Irrelevant Step
		printf("%d\n", nope);
	return 0;
}