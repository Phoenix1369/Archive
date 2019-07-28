#include <cstdio>
#include <cstdlib>
int A, B;

int main()
{
	scanf(" %d%d", &A, &B);
	if((A <= 0) && (0 <= B))
		puts("Zero");
	else if((0 < A) || ((B-A) & 1))
		puts("Positive");
	else
		puts("Negative");
	return 0;
}