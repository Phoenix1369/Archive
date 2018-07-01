#include <cstdio>
#include <cstdlib>
#include <queue>
#include <vector>
typedef long long lld;
typedef std::vector<int> vin;
const int MAXN = 2E5+5;
lld	A[MAXN]{ };
int D, K, N;

struct CMP {
	bool operator () (const int& l, const int& r) const {
		return std::abs(A[l]) > std::abs(A[r]);
	}
};
std::priority_queue<int,vin,CMP> heap;

int main()
{
	scanf(" %d%d%d", &N, &K, &D);
	int neg=0, nil=0;
	for(int i = 0; i < N; ++i)
	{
		scanf("%lld", &A[i]);
		if(A[i] < 0LL) ++neg;
		else if(!A[i]) ++nil;
	}
	for(int i = 0; (i < N) && nil && K; ++i) if(!A[i])
	{	// Remove Zeroes
		if(neg & 1)
			A[i] = +D;
		else
		{
			A[i] = -D;
			++neg;
		}
		--nil;
		--K;
	}
	for(int i = 0; i < N; ++i)
		heap.push(i);
	if((neg & 1) == 0)
	{	// Toggle Sign
		int cur = heap.top();
		heap.pop();
		int del = std::abs(A[cur]) / D + 1;
		int mov = std::min(del, K);
		if(A[cur] > 0)
			A[cur] -= 1LL*D*mov;
		else
			A[cur] += 1LL*D*mov;
		heap.push(cur);
		K -= mov;
	}
	while(K)
	{	// Maximize Magnitude
		int cur = heap.top();
		heap.pop();
		if(A[cur] > 0)
			A[cur] += D;
		else
			A[cur] -= D;
		heap.push(cur);
		--K;
	}
	for(int i = 0; i < N; ++i)
		printf("%lld ", A[i]);
	putchar('\n');
	return 0;
}