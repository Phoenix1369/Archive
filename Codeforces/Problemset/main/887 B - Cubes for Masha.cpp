#include <algorithm>
#include <cstdio>
const int DECM = 10;
const int L = 1<<3;
bool A[3][DECM]{ };
int   cnt[DECM]{ };
int digit[DECM]{ };
int N, num;

bool solve(int M)
{
	int D = 0;
	while(M)
	{	// Extract Digits
		digit[D++] = M % DECM;
		M /= DECM;
	}
	int tem[D];
	for(int mask = 1; mask < L; ++mask)
		if(__builtin_popcount(mask) == D)
		{	// Choose Subset of Cubes
			int j = 0;
			for(int bit = 0; bit < 3; ++bit)
				if((mask >> bit) & 1)
					tem[j++] = bit;
			do {	// Permute Cubes
				bool yes = true;
				for(int k = 0; k < D; ++k)
					yes &= A[tem[k]][digit[k]];
				if(yes) return true;
			} while(std::next_permutation(tem, tem+D));
		}
	return false;
}

int main()
{
	scanf("%d", &N);
	for(int i = 0; i < N; ++i)
	for(int j = 0; j < 6; ++j)
	{	// Duplicate Digits
		scanf("%d", &num);
		A[i][num] = true;
	}
	int ret = 0;
	while(solve(ret+1)) ++ret;
	printf("%d\n", ret);
	return 0;
}
