#include <cstdio>
#include <cstring>
const int MAXC = 2e5+5;
char s[MAXC]{ };
int prv=-1, ret=0;

void ac(int i) { prv=i; ++ret; }

int main()
{
	scanf(" %s", s);
	int L = strlen(s);
	for(int i = 0; i < L; ++i)
	{
		s[i] = (s[i]-'0') % 3;
		if(s[i] != 0)
		{
			if(prv == i-2)
			{	// (12, 21)
				if(s[i] != s[i-1])
					ac(i);
			}
			else if(prv == i-3)
				ac(i);	// (12, 21, 111, 222)
		}
		else
			ac(i);
	}
	printf("%d\n", ret);
    return 0;
}