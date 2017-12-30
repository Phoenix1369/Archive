#include <cstdio>
#include <cstring>
const int MAXC = 55;
const char * VOW = "aeiou";
char buff[MAXC]{ };
int ret=0;

int main()
{
	scanf(" %s", buff);
	for(char * ptr = buff; *ptr; ++ptr)
		if(strchr(VOW, *ptr) != nullptr)
			++ret;
		else if((*ptr <= '9') && ((*ptr-'0') & 1))
			++ret;
	printf("%d\n", ret);
	return 0;
}