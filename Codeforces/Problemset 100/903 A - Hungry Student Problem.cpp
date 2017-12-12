#include <cstdio>
const int MAXX = 101;
bool  cfk[MAXX]{ };
int N, x;

int main()
{
	for(int i = 0; i < MAXX; i += 3)
	for(int j = 0; i+j < MAXX; j += 7)
		cfk[i+j] = true;
	scanf("%d", &N);
	for(int _ = 0; _ < N; ++_)
	{
		scanf("%d", &x);
		puts(cfk[x] ? "YES" : "NO");
	}
	return 0;
}