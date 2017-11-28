#include <cstdio>
#include <cstring>
const int MAXC = 105;
char word[MAXC]{ };
typedef long long lld;
lld ret = 0LL;

int main()
{
	scanf(" %s", word);
	int L = strlen(word);
	for(int i = 0; i < L; ++i) if(word[i] == 'Q')
	for(int j = i+1; j < L; ++j) if(word[j] == 'A')
	for(int k = j+1; k < L; ++k) if(word[k] == 'Q')
		++ret;
	printf("%lld\n", ret);
	return 0;
}
