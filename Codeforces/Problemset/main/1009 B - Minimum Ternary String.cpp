#include <cstdio>
#include <cstring>
const int MAXC = 1E5+5;
char buff[MAXC]{ };
int cnt[3]{ };
int L;

void rep_char(char d, int c)
{
	for(int i = 0; i < c; ++i)
		putchar(d);
}

void solve(int before)
{
	for(int i = 0; i < before; ++i)
		if(buff[i] != '1')
			putchar(buff[i]);
	rep_char('1', cnt[1]);
	for(int i = before; i < L; ++i)
		if(buff[i] != '1')
			putchar(buff[i]);
	putchar('\n');
}

int main()
{
	scanf(" %s", buff);
	for(char * ptr = buff; *ptr; ++ptr)
		++cnt[*ptr-'0'];
	if(!cnt[2])
	{
		rep_char('0', cnt[0]);
		rep_char('1', cnt[1]);
		putchar('\n');
	}
	else
	{	// Put '1's before first '2'
		L = strlen(buff);
		int two = 0;
		for(int i = 0; i < L; ++i) if(buff[i] == '2')
		{
			two = i;
			break;
		}
		solve(two);
	}
    return 0;
}