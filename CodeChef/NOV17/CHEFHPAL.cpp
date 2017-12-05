#include <algorithm>
#include <cstdio>
const int MAXN = 1E5+5;
const char * S = "abbaab"; // "abb" + xor(rev("abb"))
char word[MAXN]{ };
int A, N, T;

int main()
{
	scanf("%d", &T);
	for(int _ = 0; _ < T; ++_)
	{
		scanf(" %d%d", &N, &A);
		if(A == 1)
		{	// Single Letter
			printf("%d ", N);
			for(int i = 0; i < N; ++i)
				putchar('a');
			putchar('\n');
			continue;
		}
		if(A >= 3)
		{	// Only Length One
			printf("1 ");
			for(int i = 0; i < N; ++i)
				putchar('a'+(i%3));
			putchar('\n');
			continue;
		}
		// Case: A = 2
		int H = N / 2;
		for(int i = 0; i < H; ++i)
			word[i] = 'a';
		for(int i = H; i < N; ++i)
			word[i] = 'b';
		word[N] = '\0';
		int ret = N-H;
		for(int i = 0; i < H; ++i)
		{	// Swapping Algorithm: Reverse "a.ab.b"
			int p = std::max(std::max(H-i-1, i+1+std::min(H-i-1,i+1)*2),
					 std::max(N-H-i-1, i+1+std::min(i+1, N-H-i-1)*2));
			if(p > ret) break;
			std::swap(word[H-i-1], word[H+i]);
			ret = p;
		}
		if(ret > 4)
		{	// Minimal Internal Palindromic Substring
			for(int i = 0; i < N; ++i)
				word[i] = S[i%6];
			ret = 4;
		}
		printf("%d ", ret);
		puts(word);
	}
	return 0;
}