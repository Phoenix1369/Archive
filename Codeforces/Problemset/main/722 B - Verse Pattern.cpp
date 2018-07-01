#include <cstdio>
#include <cstring>
const char * VOW = "aeiouy";
const int MAXC = 105;
char buff[MAXC]{ };
int	P[MAXC]{ };
int N;

int main()
{
	scanf("%d", &N);
	for(int i = 0; i < N; ++i)
		scanf("%d", &P[i]);
	scanf("\n");
	bool yes = true;
	for(int i = 0; i < N; ++i)
	{
		int cnt = 0;
		fgets(buff, MAXC, stdin);
		for(char * ptr = buff; *ptr; ++ptr)
			if(strchr(VOW, *ptr)) ++cnt;
		yes &= (cnt == P[i]);
	}
	puts(yes ? "YES" : "NO");
	return 0;
}