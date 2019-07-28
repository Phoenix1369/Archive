#include <algorithm>
#include <cstdio>
const int MAXN = 1E5+5;
const int LOGN = 18;
int    dp[MAXN]{ };
int   loc[MAXN]{ };
int   spt[LOGN][MAXN]{ };
//    spt[I][J] = Farthest Child of [J] after [1<<I] days
int A, B, D, N, Q;

int main()
{
	scanf("%d", &N);
	for(int i = 1; i <= N; ++i)
	{
		scanf("%d", &loc[i]);
		dp[i] = MAXN;
	}
	scanf(" %d%d", &D, &Q);
	loc[N+1] = loc[N]+D+1; // Past-the-End Element
	dp[1] = 0;
	int tail = 1;
	for(int head = 1; head <= N; ++head)
	{	// Init Sparse Table
		if(tail < head)
			tail = head;
		bool end = (loc[tail]-loc[head] > D);
		spt[0][head] = tail-end;
		while((tail <= N) && (loc[tail]-loc[head] <= D))
		{
			dp[tail] = std::min(dp[head]+1, dp[tail]);
			spt[0][head] = tail;
			++tail;
		}
	}
	for(int day = 1; day < LOGN; ++day) // f^(2^day)(x)
		for(int hot = 1; hot <= N; ++hot) // Hotel ID
			spt[day][hot] = spt[day-1][spt[day-1][hot]];
	for(int _ = 0; _ < Q; ++_)
	{
		scanf(" %d%d", &A, &B);
		if(A > B) std::swap(A, B);
		int cnt, ret=0;
		do {
			cnt = 0;
			while((cnt+1 < LOGN) && (spt[cnt+1][A] < B)) ++cnt;
			A = spt[cnt][A];
			ret += 1<<cnt;
		} while(A < B);
		printf("%d\n", ret);
	}
	return 0;
}