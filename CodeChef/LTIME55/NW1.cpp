#include <cstdio>
#include <cstring>
const int MAXC = 7;
const char * WEEK[MAXC] = { "mon", "tues", "wed", "thurs", "fri", "sat", "sun" };
char buff[MAXC]{ };
int beg, T, W;

int main()
{
	scanf("%d", &T);
	for(int _ = 0; _ < T; ++_)
	{
		scanf(" %d%s", &W, buff);
		for(int i = 0; i < MAXC; ++i) if(strcmp(buff, WEEK[i]) == 0)
		{
			int bas = W / MAXC;
			int rem = W % MAXC;
			for(int j = 0; j < MAXC; ++j)
				printf("%d ", bas + ((j + (j < i)*MAXC - i) < rem));
			putchar('\n');
			break;
		}
	}
	return 0;
}