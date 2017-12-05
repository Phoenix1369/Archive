#include <cstdio>
#include <cstring>
const int MAXC = 1E5+5;
char buff[MAXC]{ };
int cnt[2], L, pos[2], T;
 
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf(" %s", buff);
		L = strlen(buff);
		cnt[0]=cnt[1]=0;
		pos[1]=pos[1]=-1;
		for(int i = 0; i < L; ++i) if(buff[i] >= 'A')
		{
			int d = buff[i]-'A';
			if(pos[d] == -1) pos[d] = i-1;
			cnt[d] += i-pos[d];
			pos[d] = i;
			pos[d^1] = -1;
		}
		printf("%d %d\n", cnt[0], cnt[1]);
	}
	return 0;
}
