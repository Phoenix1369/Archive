#include <cstdio>
const int MAXN = 1E5+5;
int   cnt[MAXN]{ };
int M=0, N, P;

struct BinaryIndexedTree
{
	int data[MAXN]{ };

	void add(int x)
	{
		for(int i = x; i <= N; i += i & -i)
			++data[i];
	}

	int get(int x)
	{
		int sum = 0;
		for(int i = x; i >= 1; i -= i & -i)
			sum += data[i];
		return	sum;
	}
} bintr;

int main()
{
	scanf("%d", &N);
	for(int i = 0; i < N; ++i)
	{
		scanf("%d", &P);
		int over = bintr.get(N-P);
		if(!over)
		{	// P is a record
			--cnt[P];
			M = P;
		}
		else if(over == 1) // P is nearly a record
			++cnt[M];
		bintr.add(N-P+1);
	}
	int ret = 1;
	for(int i = 2; i <= N; ++i)
		if(cnt[i] > cnt[ret])
			ret = i;
	printf("%d\n",	ret);
	return 0;
}
