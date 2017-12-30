#include <algorithm>
#include <cstdio>
const int MAXN = 505;
int C[MAXN], F[MAXN], S[MAXN];
int N;

int main()
{
	scanf("%d", &N);
	for(int i = 1; i < N; ++i)
		scanf("%d%d%d", &C[i], &S[i], &F[i]);
	for(int i = 1; i <= N; ++i)
	{
		int time = 0;
		for(int j = i; j < N; ++j)
		{
			time  = std::max(S[j], time);
			int R = (time-S[j]) % F[j];
			if(R) time += F[j]-R;
			time += C[j];
		}
		printf("%d\n", time);
	}
	return 0;
}