#include <algorithm>
#include <cstdio>
const int N = 3;
int	K[N]{ };

int main()
{
	for(int i = 0; i < N; ++i)
		scanf("%d", &K[i]);
	std::sort(K, K+N);
	puts(	((K[0] == 1) || (K[1] == 2)  ||
		((K[0] == 3) && (K[2] == 3)) ||
		((K[0] == 2) && (K[1] == 4) && (K[2] == 4))) ? "YES" : "NO" );
	return 0;
}