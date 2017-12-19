#include <cstdio>
const int MAXH = 1E5+5;
int	A[MAXH]{ };
int dup=0, H, node;

void rep(int mul)
{
	for(int i = 0; i < mul; ++i)
		printf("%d ", node);
}

void get_tree(void (*f)(int))
{
	node = 0;
	for(int k = 0; k <= H; node += A[k++])
		f(k);
	putchar('\n');
}

void one(int k) { rep(A[k]); }

void two(int k)
{	// Send child to a different parent
	bool B = (k == dup);
	if(B) printf("%d ", node-1);
	rep(A[k]-B);
}

int main()
{
	scanf("%d", &H);
	for(int i = 0; i <= H; ++i)
	{
		scanf("%d", &A[i]);
		if(i && (A[i] > 1) && (A[i-1] > 1))
			dup = i;
	}
	if(!dup) return puts("perfect"), 0;
	puts("ambiguous");
	get_tree(one);
	get_tree(two);
	return 0;
}