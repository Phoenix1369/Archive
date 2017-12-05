#include <cstdio>
int N, P, T;

void make_palin()
{
	putchar('a');
	for(int i = 2; i < P; ++i)
		putchar('b');
	putchar('a');
}

int main()
{
	scanf("%d", &T);
	for(int _ = 0; _ < T; ++_)
	{
		scanf(" %d%d", &N, &P);
		if(P > 2)
		{
			for(int i = N/P; i >= 1; --i)
				make_palin();
			putchar('\n');
		}
		else
			puts("impossible");
	}
	return 0;
}