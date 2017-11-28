#include <cstdio>
#include <cstring>
char word[105];
int L, N;

int main()
{
	scanf("%d", &N);
	for(int i = 0; i < N; ++i)
	{
		scanf(" %s", word);
		L = strlen(word);
		if(L <= 10)
			puts(word);
		else
			printf("%c%d%c\n", word[0], L-2, word[L-1]);
	}
}