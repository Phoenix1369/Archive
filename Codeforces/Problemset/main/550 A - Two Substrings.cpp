#include <cstdio>
#include <cstring>
const int MAXC = 1E5+5;
char buff[MAXC]{ };
int pos[2]{ };

int main()
{
	scanf(" %s", buff);
	int L = strlen(buff);
	for(int i = 1; i < L; ++i)
		if((buff[i-1] <= 'B') && (buff[i] == (buff[i-1] ^ 3)))
		{
			int num = buff[i]-'A';
			if(pos[num^1] && (pos[num^1] <= i-2))
				return puts("YES"), 0;
			if(!pos[num]) pos[num] = i;
		}
	puts("NO");
	return 0;
}
