#include <cstdio>
const int MAXX = 105;
bool  mex[MAXX]{ };
int N, num, ret=0, X;

int main()
{
	scanf(" %d%d", &N, &X);
	for(int i = 0; i < N; ++i)
	{
		scanf("%d", &num);
		mex[num] = true;
	}
	for(int i = 0; i < X; ++i)
		if(!mex[i]) ++ret;
	printf("%d\n", ret + mex[X]);
	return 0;
}
