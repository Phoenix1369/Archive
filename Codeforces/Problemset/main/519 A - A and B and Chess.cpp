#include <cstdio>
const int MAXB = 8;
char V[26]{ };
char C;

int main()
{
	V['P'-'A'] = 1;
	V['B'-'A'] = V['N'-'A'] = 3;
	V['R'-'A'] = 5;
	V['Q'-'A'] = 9;
	int B=0, W=0;
	for(int i = 0; i < MAXB; ++i)
		for(int j = 0; j < MAXB; ++j)
		{
			scanf(" %c", &C);
			if(C == '.') continue;
			if(C <= 'Z')
				W += V[C-'A'];
			else
				B += V[C-'a'];
		}
	puts((W > B) ? "White" : (B > W) ? "Black" : "Draw");
	return 0;
}