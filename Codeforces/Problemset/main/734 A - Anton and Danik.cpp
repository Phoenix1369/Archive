#include <cstdio>
const int MAXC = 1E5+5;
char buff[MAXC]{ };
int   cnt[2]{ };
int N;

int main()
{
	scanf("%d", &N);
	scanf(" %s", buff);
	for(int i = 0; i < N; ++i)
		++cnt[(buff[i] == 'D')];
	puts((cnt[0] > cnt[1]) ? "Anton" : (cnt[0] < cnt[1]) ? "Danik" : "Friendship");
	return 0;
}
