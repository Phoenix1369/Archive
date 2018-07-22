#include <cstdio>
#include <cstring>
const int MAXC = 105;
const char * VOWEL = "aeiou";
char s[MAXC];

int main()
{
	scanf(" %s", s);
	int L = strlen(s);
	s[L] = '\n';	// '\0' is part of s
	for(int i = 0; i < L; ++i)
		if(!strchr(VOWEL, s[i]) && (s[i] != 'n'))
			if(!strchr(VOWEL, s[i+1]))
				return puts("NO"), 0;
	puts("YES");
    return 0;
}
