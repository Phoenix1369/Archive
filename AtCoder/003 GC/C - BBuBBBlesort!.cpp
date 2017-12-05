#include <algorithm>
#include <cstdio>
#include <unordered_map>
const int MAXN = 1E5+5;
std::unordered_map<int,int> chain;
int	A[MAXN]{ };
int ans=0, N;

int main()
{
	scanf("%d", &N);
	chain.reserve(N);
	for(int i = 0; i < N; ++i)
	{
		scanf("%d", &A[i]);
		chain[A[i]] = (i & 1);
	}
	std::sort(A, A+N);
	for(int i = 0; i < N; ++i)
		if(chain.at(A[i]) != (i & 1))
			++ans;
	printf("%d\n", ans>>1);
	return 0;
}