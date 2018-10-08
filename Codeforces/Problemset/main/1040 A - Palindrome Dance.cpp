#include <algorithm>
#include <cstdio>
const int MAXN = 25;
int a, b, n, ret=0;
int c[MAXN]{ };
bool yes=true;

int main()
{
	scanf(" %d%d%d", &n, &a, &b);
	for(int i = 0; i < n; ++i)
		scanf("%d", &c[i]);
	int head=0, tail=n-1, z=std::min(a,b);
	while(head <= tail)
	{
		if((c[head] == 2) && (c[tail] == 2))
			ret += (head == tail) ? z : 2*z;
		else if(c[head] == 2)
			ret += (c[tail]) ? b : a;
		else if(c[tail] == 2)
			ret += (c[head]) ? b : a;
		else if(c[head] != c[tail])
			yes = false;
		++head;
		--tail;
	}
	if(yes)
		printf("%d\n", ret);
	else
		puts("-1");
	return 0;
}
