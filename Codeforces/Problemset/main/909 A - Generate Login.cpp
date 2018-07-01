#include <cstdio>
#include <cstring>
const int MAXC = 15;
char buff[2][MAXC]{ };

int main()
{
	for(int i = 0; i < 2; ++i)
		scanf(" %s", buff[i]);
	putchar(buff[0][0]);
	int L = strlen(buff[0]);
	for(int i = 1; (i < L) && (buff[0][i] < buff[1][0]); ++i)
		putchar(buff[0][i]);
	putchar(buff[1][0]);
	putchar('\n');
	return 0;
}