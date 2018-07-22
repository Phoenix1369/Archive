#include <cstdio>
#include <cstring>
const int MAXC = 205;
char S[MAXC]{ }, T[MAXC];

bool rotate_equals()
{
	int L = strlen(S);
	for(int i = 0; i < L; ++i)
	{
		if(strcmp(S+i, T) == 0)
			return true;
		S[i+L] = S[i];
	}
	return false;
}

int main()
{
	scanf(" %s%s", S, T);
	puts(rotate_equals() ? "Yes" : "No");
    return 0;
}
