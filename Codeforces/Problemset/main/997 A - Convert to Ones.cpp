#include <cstdio>
typedef long long lld;
const int MAXN = 3E5+5;
char buff[MAXN]{ };
int N, X, Y, Z=0;

int main()
{
	scanf(" %d%d%d", &N, &X, &Y);
	scanf(" %s", buff);
	for(char * ptr = buff; *ptr;)
	{
		while(*ptr == '1') ++ptr;
		if(*ptr == '0') ++Z;
		while(*ptr == '0') ++ptr;
	}
	printf("%lld\n", ((X < Y) && Z) ? ((Z-1LL)*X+Y) : (1LL*Z*Y));
    return 0;
}