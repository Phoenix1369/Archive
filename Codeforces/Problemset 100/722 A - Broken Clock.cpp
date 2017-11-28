#include <cstdio>
int F, H, M;

int main()
{
	scanf("%d", &F);
	scanf("%d:%d", &H, &M);
	if(M >= 60) M %= 10;
	if(F == 12)
	{
		if((H > 12) && (H % 10))
			H %= 10; // Preserve 1's Digit
		else if(!H || (H > 12))
			H = 10;  // 00->10 or X0->10
	}
	else if(H >= 24) // (F == 24)
		H %= 10;
	printf("%02d:%02d\n", H, M);
	return 0;
}
