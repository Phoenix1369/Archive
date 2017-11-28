#include <cstdio>
#include <cstring>
const int MAXC = 105;
const char * VOWEL = "aeiouy";
char buff[MAXC]{ };

int main()
{
	scanf(" %s", buff);
	for(char * ptr = buff; *ptr; ++ptr)
	{
		if(*ptr <= 'Z') *ptr += ' '; // To Lowercase
		if(strchr(VOWEL, *ptr) != nullptr) continue;
		putchar('.'), putchar(*ptr);
	}
	putchar('\n');
	return 0;
}
