#include <cstdio>
#include <map>
const int MAXN = 2E5+5;
int	P[MAXN]{ };
std::map<int,int> last;
int A, N, room=1;

int main()
{
	scanf("%d", &N);
	P[0] = 1;
	last[1] = 0;
	for(int i = 1; i <= N; ++i)
	{
		scanf("%d", &A);
		if(last.count(P[A]) && last.at(P[A]) == A)
		{
			P[i] = P[A];
			last[P[A]] = i;
		}
		else
		{
			P[i] = ++room;
			last[room] = i;
		}
	}
	printf("%d\n", room);
	return 0;
}
