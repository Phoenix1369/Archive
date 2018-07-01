#include <cstdio>
int N, play=3, win;

int main()
{
	scanf("%d", &N);
	bool valid = true;
	for(int i = 0; i < N; ++i)
	{
		scanf("%d", &win); --win;
		valid &= ((play >> win) & 1);
		play = (play ^ 7) | (1 << win);
	}
	puts(valid ? "YES" : "NO");
	return 0;
}
