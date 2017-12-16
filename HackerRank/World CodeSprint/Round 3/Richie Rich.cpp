#include <cstdio>
const int MAXC = 1E5+5;
bool  alt[MAXC]{ };
char buff[MAXC]{ };
int C=0, K, N;

int main()
{
	scanf(" %d%d%s", &N, &K, buff);
	for(int l=0, r=N-1; l <= r; ++l, --r)
		if(buff[l] != buff[r]) C++;
	if(K < C) return puts("-1"), 0;
	for(int l=0, r=N-1; l <= r; ++l, --r) if(buff[l] != buff[r])
	{
		if(buff[l] < buff[r])
			buff[l] = buff[r];
		else
			buff[r] = buff[l];
		alt[l] = true;
		--K;
	}
	for(int l=0, r=N-1; K && (l <= r); ++l, --r) if(buff[l] != '9')
	{	// Maximize Result
		if(alt[l] || (l == r))
		{
			buff[l] = buff[r] = '9';
			--K;
		}
		else if(K >= 2)
		{
			buff[l] = buff[r] = '9';
			K -= 2;
		}
	}
	puts(buff);
	return 0;
}