#include <cstdio>
const int MAXA = 26;
const int MAXN = 4e5+5;
char buff[MAXN]{ };
int cnt[MAXA]{ };
int k, n, sum=0;
char part=0;

int main()
{
	scanf(" %d%d", &n, &k);
	scanf(" %s", buff);
	for(char * ptr = buff; *ptr; ++ptr)
		++cnt[*ptr-'a'];
	for(int i = 0; i < MAXA; ++i)
		if(sum+cnt[i] >= k)
		{
			part = 'a'+i;
			sum = k - sum;
			break;
		}
		else
			sum += cnt[i];
	for(char * ptr = buff; *ptr; ++ptr)
		if(*ptr > part)
			putchar(*ptr);
		else if(*ptr == part)
		{
			if(sum)
				--sum;
			else
				putchar(part);
		}
	putchar('\n');
    return 0;
}
