#include <cstdio>
#include <deque>
const int MAXN = 1E5+5;
int	A[MAXN]{ };
std::deque<int> monoQ;
int D, N, T;

int main()
{
	scanf("%d", &T);
	for(int _ = 0; _ < T; ++_)
	{
		scanf("%d%d", &N, &D);
		monoQ.clear();
		int ret = N+1;
		for(int h=1, t=1; t <= N; ++t)
		{
			scanf("%d", &A[t]);
			if(A[t] >= D) ret = 1;
			A[t] += A[t-1];
			while(!monoQ.empty() && (A[t] - A[monoQ.front()-1] >= D))
			{
				h = monoQ.front();
				monoQ.pop_front();
			}
			if(A[t] - A[h-1] >= D)
				ret = std::min(t-h+1, ret);
			while(!monoQ.empty() && (A[t] - A[monoQ.back()-1] <= 0))
				monoQ.pop_back();
			monoQ.push_back(t+1);
		}
		if(ret <= N)
			printf("%d\n", ret);
		else
			puts("-1");
	}
	return 0;
}