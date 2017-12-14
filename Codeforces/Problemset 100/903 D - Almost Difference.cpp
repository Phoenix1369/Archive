#include <cstdio>
#include <unordered_map>
typedef long long unsigned llu;
const int MAXN = 2E5+5;
int	A[MAXN]{ };
std::unordered_map<int,int> cnt;
llu retn, retp;
int N;

int main()
{
	scanf("%d", &N);
	cnt.reserve(N);
	retn = retp = 0LLU;
	for(int i = 0; i < N; ++i)
	{	// Everything Before: Add
		int pos = i;
		scanf("%d", &A[i]);
		for(int j = -1; j <= 1; ++j)
			if(cnt.count(A[i]+j))
				pos -= cnt.at(A[i]+j);
		retp += 1LLU*A[i]*pos;
		++cnt[A[i]];
	}
	cnt.clear();
	cnt.reserve(N);
	for(int i = N-1; i >= 0; --i)
	{	// Everything After: Sub
		int pos = N-i-1;
		for(int j = -1; j <= 1; ++j)
			if(cnt.count(A[i]+j))
				pos -= cnt.at(A[i]+j);
		retn += 1LLU*A[i]*pos;
		++cnt[A[i]];
	}
	if(retp < retn)
		printf("-%llu\n", retn-retp);
	else
		printf("%llu\n", retp-retn);
	return 0;
}