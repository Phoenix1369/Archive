#include <cstdio>
#include <queue>
typedef long long lld;
const int MAXN = 2E5+5;
int A[MAXN], B[MAXN];
std::deque<int> maxQ, minQ;
int N;

int main()
{
	scanf("%d", &N);
	for(int i = 1; i <= N; ++i)
		scanf("%d", &A[i]);
	for(int i = 1; i <= N; ++i)
		scanf("%d", &B[i]);
	lld ret = 0;
	for(int l = 1, r = 1; r <= N; ++r)
	{	// Maintain Monotonic Invariant
		while(!maxQ.empty() && (A[maxQ.back()] <= A[r]))
			maxQ.pop_back();	// A[maxQ[0]] > A[maxQ[1]]
		while(!minQ.empty() && (B[minQ.back()] >= B[r]))
			minQ.pop_back();	// B[minQ[0]] < B[minQ[1]]
		maxQ.push_back(r);
		minQ.push_back(r);
		while((l <= r) && (A[maxQ.front()] > B[minQ.front()]))
		{	// A[l,r]-B[l,r] >= A[l+1,r]-B[l+1,r]
			++l;
			while(!maxQ.empty() && (maxQ.front() < l))
				maxQ.pop_front();
			while(!minQ.empty() && (minQ.front() < l))
				minQ.pop_front();
		}
		if(!maxQ.empty() && !minQ.empty() && (A[maxQ.front()] == B[minQ.front()]))
			ret += std::min(maxQ.front(), minQ.front()) - l + 1;
	}
	printf("%lld\n", ret);
	return 0;
}
