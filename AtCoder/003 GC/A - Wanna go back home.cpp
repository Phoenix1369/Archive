#include <cstdio>
const int MAXC = 1005;
char buff[MAXC]{ };
bool cnt[26]{ };

int main()
{
	scanf(" %s", buff);
	for(char * ptr = buff; *ptr; ++ptr)
		cnt[*ptr-'A'] = true;
	bool done = (cnt['E'-'A'] == cnt['W'-'A']) && (cnt['N'-'A'] == cnt['S'-'A']);
	puts(done ? "Yes" : "No");
	return 0;
}