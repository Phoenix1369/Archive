#include <cstdio>
int A[2], C, H[2], heal=-1;

int main()
{
	scanf(" %d%d%d%d%d", &H[0], &A[0], &C, &H[1], &A[1]);
	int kill = (H[1] + A[0] - 1) / A[0];
	for(int k = 0; heal == -1; ++k)
		if((H[0] + C*k + A[1] - 1) / A[1] >= kill+k)
			heal = k;
	printf("%d\n", heal+kill);
	for(int i = 0; i < heal; ++i)
		puts("HEAL");
	for(int i = 0; i < kill; ++i)
		puts("STRIKE");
	return 0;
}