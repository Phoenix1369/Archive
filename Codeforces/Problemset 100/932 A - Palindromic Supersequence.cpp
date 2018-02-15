#include <cstdio>
#include <cstring>
const int MAXC = 1005;
char buff[MAXC]{ };

int main()
{
	scanf(" %s", buff);
	printf(buff);
	for(int i = strlen(buff)-1; i >= 0; --i)
		putchar(buff[i]);
	putchar('\n');
	return 0;
}