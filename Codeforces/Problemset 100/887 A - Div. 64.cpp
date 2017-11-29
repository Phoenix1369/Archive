#include <cstdio>
const int LOGK = 6;
const int MAXC = 105;
char buff[MAXC]{ };
int Z=0;

int main()
{
	scanf(" %s", buff);
	char * ptr = buff;
	while(*ptr && (*ptr == '0')) ++ptr;
	while(*ptr && (Z < LOGK))
	{
		if(*ptr == '0') ++Z;
		++ptr;
	}
	puts((Z >= LOGK) ? "yes" : "no");
	return 0;
}
