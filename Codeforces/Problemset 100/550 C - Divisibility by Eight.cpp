#include <cstdio>
#include <cstring>
const int MAXC = 105;
char buff[MAXC]{ };

int main()
{
	scanf(" %s", buff+2);
	buff[0] = buff[1] = '0';
	int L = strlen(buff);
	for(int i = 0; i < L; ++i)
	for(int j = i+1; j < L; ++j)
	for(int k = j+1; k < L; ++k)
	{
		int num = (buff[i]-'0')*100 + (buff[j]-'0')*10 + (buff[k]-'0');
		if((num & 7) == 0)
			return printf("YES\n%d\n", num) & 0;
	}
	puts("NO");
	return 0;
}
