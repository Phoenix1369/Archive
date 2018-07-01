#include <algorithm>
#include <cstdio>
int E=0, M, N;

int main()
{
	scanf(" %d%d", &N, &M);
	for(int i = 0; i < N; ++i)
	{
		int a, b;
		scanf(" %d%d", &a, &b);
		if((a > E) || (E >= M)) break;
		E = std::max(b, E);
	}
	puts((E >= M) ? "YES" : "NO");
	return 0;
}