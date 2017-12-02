#include <cstdio>
const int MAXN = 1E6+5;
int print[MAXN]{ };
int cmd, mov, N, Q;
bool swap = false; // If False: Odd = Odd, Eve = Eve

int main()
{
	scanf(" %d%d", &N, &Q);
	int one=0, two=1; // Two Pointers
	for(int i = 0; i < Q; ++i)
	{
		scanf("%d", &cmd);
		if(cmd == 1)
		{
			scanf("%d", &mov);
			mov = (mov + N) % N;
			if(mov)
			{
				if(mov & 1)
					swap ^= true;
				one += mov; one %= N;
				two += mov; two %= N;
			}
		}
		else
		{
			if(!swap)
			{
				if(++one >= N)
					one = 0;
				if(--two < 0)
					two = N-1;
			}
			else
			{
				if(--one < 0)
					one = N-1;
				if(++two >= N)
					two = 0;
			}
			swap ^= true;
		}
	}
	int N2 = N >> 1;
	for(int i = one, j = 0, k = 1; j < N2; i = (i + 2) % N, ++j, k += 2) print[i] = k;
	for(int i = two, j = 0, k = 2; j < N2; i = (i + 2) % N, ++j, k += 2) print[i] = k;
	for(int i = 0; i < N; ++i)
		printf("%d ", print[i]);
	return 0;
}
