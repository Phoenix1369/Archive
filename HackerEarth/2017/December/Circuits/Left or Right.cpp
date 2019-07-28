#include <algorithm>
#include <cstdio>
#include <vector>
#define ALL(x) (x).begin(), (x).end()
typedef std::vector<int> vin;
const int MAXZ = 2E5+5;
vin	T[MAXZ]{ };
int A, N, Q;

int main()
{
	scanf(" %d%d", &N, &Q);
	for(int i = 0; i < N; ++i)
	{
		scanf("%d", &A);
		T[A].push_back(i);
	}
	for(int _ = 0; _ < Q; ++_)
	{
		char cmd; int y, z;
		scanf("%d%d %c", &y, &z, &cmd);
		if(T[z].empty()) { puts("-1"); continue; }
		auto ptr = std::lower_bound(ALL(T[z]), y);
		switch(cmd)
		{
		case 'L':
			if((ptr == T[z].begin()) && (*ptr > y))
				printf("%d\n", y+N-T[z].back());
			else if((ptr == T[z].end()) || (*ptr > y))
				printf("%d\n", y-*--ptr);
			else
				puts("0");
			break;
		case 'R':
			if(ptr == T[z].end())
				printf("%d\n", T[z].front()+N-y);
			else
				printf("%d\n", *ptr-y);
			break;
		}
	}
	return 0;
}