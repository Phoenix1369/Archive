#include <cstdio>
const int MAXC = 15;
char	S[MAXC]{ };
bool yes=true;
int A, B;

int main()
{
	scanf("%d%d %s", &A, &B, S);
	for(int i = A+B; i >= 0; --i)
		if(i != A)
			yes &= ('0' <= S[i]) && (S[i] <= '9');
		else
			yes &= (S[i] == '-');
	puts(yes ? "Yes" : "No");
	return 0;
}