#include <algorithm>
#include <cstdio>
#define M3(x, y, z) std::max((x), std::max((y), (z)))
int V[4]{ };

int main()
{
	for(int i = 0; i < 4; ++i)
		scanf("%d", &V[i]);
	for(int k = std::max(V[2], V[3]); k <= 2*V[2]; ++k) if(2*V[3] >= k)
	for(int j = M3(V[1], V[3],  k+1); j <= 2*V[1]; ++j) if(2*V[3] <  j)
	for(int i = M3(V[0], V[3],  j+1); i <= 2*V[0]; ++i) if(2*V[3] <  i)
		return printf("%d\n%d\n%d\n", i, j, k) & 0;
	puts("-1");
	return 0;
}