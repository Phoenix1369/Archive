#include <cstdio>
#include <unordered_map>
std::unordered_map<int,int> cnt;
int A, M=0, N;

int main()
{
	scanf("%d", &N);
	cnt.reserve(N);
	for(int i = 0; i < N; ++i)
	{
		scanf("%d", &A);
		if(++cnt[A] > M)
			M = cnt.at(A);
	}
	printf("%d\n", M);
	return 0;
}