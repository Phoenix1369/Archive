#include <cstdio>
int N;

int digit_sum(int num)
{
	int res = 0;
	while(num)
	{
		res += num % 10;
		num /= 10;
	}
	return res;
}

int main()
{
	scanf("%d", &N);
	puts((N % digit_sum(N)) ? "No" : "Yes");
	return 0;
}
