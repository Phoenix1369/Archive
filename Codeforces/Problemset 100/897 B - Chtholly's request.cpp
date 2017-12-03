#include <cstdio>
const int BASE = 10;
const int MAXD = 20;
int	D[MAXD]{ };
int K, len=0, P, ret=0;

int get_num()
{
	int num = 0;
	for(int i = 0; i <= len; ++i)
		num = (10LL*num + D[i]) % P;
	for(int i = len; i >= 0; --i)
		num = (10LL*num + D[i]) % P;
	return num;
}

int next()
{	// Advances the Palindrome Generator
	int mid = len;
	++D[mid];
	while(D[mid] >= BASE)
	{
		D[mid] = 0;
		if(--mid < 0) break;
		++D[mid];
	}
	if(!D[0])
	{	// Extend Palindrome
		mid = ++len;
		D[0] = 1;
	}
	return get_num();
}

int main()
{
	scanf(" %d%d", &K, &P);
	for(int i = 0; i < K; ++i)
		ret = (next() + ret) % P;
	printf("%d\n", ret);
	return 0;
}
