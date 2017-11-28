#include <algorithm>
#include <cstdio>
int A[6];

int main()
{
	for(int i = 0; i < 6; ++i)
		scanf("%d", &A[i]);
	std::sort(A, A+6);
	bool same = false;
	do {
		int sum[2]{ };
		for(int i = 0; i < 3; ++i)
			sum[0] += A[i];
		for(int i = 0; i < 3; ++i)
			sum[1] += A[i+3];
		if(sum[0] == sum[1])
		{
			same = true;
			break;
		}
	} while(std::next_permutation(A, A+6));
	puts(same ? "YES" : "NO");
	return 0;
}
