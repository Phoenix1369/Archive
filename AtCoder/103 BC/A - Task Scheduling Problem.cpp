#include <algorithm>
#include <cstdio>
int A[3]{ };

int main()
{
	for(int i = 0; i < 3; ++i)
		scanf("%d", &A[i]);
	std::sort(A, A+3);
	printf("%d\n", A[2]-A[0]);
    return 0;
}
