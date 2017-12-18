#include <cstdio>
const int MAXX = 1005;
int N, T;

int main()
{
	scanf("%d", &T);
	for(int _ = 0; _ < T; ++_)
	{
		scanf("%d", &N);
		int A=MAXX, B=0, pos;
		for(int i = 0; i < N; ++i)
		{
			scanf("%d", &pos);
			if(pos < A) A = pos;
			if(pos > B) B = pos;
		}
		printf("%d\n", B-A);
	}
	return 0;
}