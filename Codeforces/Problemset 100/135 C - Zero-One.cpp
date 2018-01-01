#include <cstdio>
#include <cstring>
const int MAXC = 1E5+5;
char buff[MAXC]{ };
int cnt[3]{ };

int main()
{
	scanf(" %s", buff);
	int L = strlen(buff);
	bool B = (buff[L-1] == '?');
	for(char * ptr = buff; *ptr; ++ptr)
		if(*ptr != '?')
			++cnt[*ptr-'0'];
		else
			++cnt[2];
	if(cnt[1] < cnt[0] + cnt[2])
		puts("00");
	if(buff[L-1] != '0')
	{
		int X = (cnt[0]-cnt[1]+cnt[2]-B*2+(L&1))>>1;
		if((0 <= X) && (X <= cnt[2]-B))
			puts("01");
	}
	if(buff[L-1] != '1')
	{
		int X = (cnt[0]-cnt[1]+cnt[2]+(L&1))>>1;
		if((0 <= X) && (X <= cnt[2]-B))
			puts("10");
	}
	if(cnt[0] + 1 < cnt[1] + cnt[2])
		puts("11");
	return 0;
}