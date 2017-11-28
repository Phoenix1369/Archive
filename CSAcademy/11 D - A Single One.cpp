#include <cstdio>
#include <set>
const int MAXN = 1E5+5;
int final[MAXN]{ };
int queue[MAXN]{ };
std::set<int> nodes;
int K, M, N, qtr[2], S;

template <typename T> T abs(T num) { return (num < 0) ? -num : num; }

void bfs(const int& src)
{
	qtr[0]=qtr[1]=0;
	queue[qtr[1]++] = src;
	while(qtr[0] < qtr[1])
	{
		int cur = queue[qtr[0]++], L, R;
		nodes.erase(cur);
		if(cur-(K-1) >= 1)
			L = cur-(K-1);
		else // Bounded by '1'
			L = K-cur+1;
		if(cur+(K-1) <= N)
			R = cur+(K-1);
		else // Bounded by 'N'
			R = N-(K-(N-cur))+1;
		for(auto itr  = nodes.lower_bound(L);
			(itr != nodes.end()) && (*itr <= R);)
		{
			if((K & 1) != (abs(cur-*itr) & 1))
			{	// Different: Odd Sub == Eve Swap
				final[*itr] = final[cur]+1;
				queue[qtr[1]++] = *itr;
				itr = nodes.erase(itr);
			}
			else
				++itr;
		}
		if(nodes.empty()) break;
	}
}

int main()
{
	scanf(" %d%d%d%d", &N, &K, &M, &S);
	for(int i = 1; i <= N; ++i)
	{
		final[i] = -1;
		nodes.insert(i);
	}
	for(int i = 0; i < M; ++i)
	{
		int tem;
		scanf("%d", &tem);
		nodes.erase(tem);
	}
	final[S] = 0; bfs(S);
	for(int i = 1; i <= N; ++i)
		printf("%d%c", final[i], (i==N)?'\n':' ');
	return 0;
}