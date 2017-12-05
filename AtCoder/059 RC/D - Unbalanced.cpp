#include <cstdio>
#include <cstring>
#include <set>
const int MAXC = 1E5+5;
char buff[MAXC]{ };
std::set<char> three;
int L;

int main()
{
	scanf(" %s", &buff);
	L = strlen(buff);
	// Cases: "XXY" or "XYX"
	if(buff[0]==buff[1])
		return puts("1 2"), 0;
	for(int i = 0; i+2 < L; ++i)
	{
		three.clear();
		for(int j = 0; j < 3; ++j)
			three.insert(buff[i+j]);
		if(three.size() <= 2U)
			return printf("%d %d\n", i+1, i+3) & 0;
	}
	puts("-1 -1");
	return 0;
}