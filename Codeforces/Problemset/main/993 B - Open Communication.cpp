#include <cstdio>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#define x first
#define y second
typedef std::pair<int,int> pii;
const int MAXN = 12;
std::unordered_map<int,int> unique;
std::unordered_set<int> both, nope;
bool pa[MAXN][2]{ }, pb[MAXN][2]{ };
pii ca[MAXN], cb[MAXN];
int m, n, ret, val;

int match(int i, int j)
{
	unique.clear();
	unique.reserve(4);
	++unique[ca[i].x];
	++unique[ca[i].y];
	++unique[cb[j].x];
	++unique[cb[j].y];
	if(unique.size() == 3u)
	{
		if(unique.at(ca[i].x) == 2)
			return ca[i].x;
		return ca[i].y;	// Note: cb[j].x != cb[j].y
	}
	return 0;
}

int main()
{
	scanf(" %d%d", &n, &m);
	for(int i = 0; i < n; ++i)
		scanf(" %d%d", &ca[i].x, &ca[i].y);
	for(int j = 0; j < m; ++j)
		scanf(" %d%d", &cb[j].x, &cb[j].y);
	both.reserve(10);
	nope.reserve(10);
	for(int i = 0; i < n; ++i)
	for(int j = 0; j < m; ++j)
		if((val = match(i, j)) != 0)
		{
			pa[i][val == ca[i].y] = pb[j][val == cb[j].y] = true;
			if(pa[i][0] && pa[i][1])
				nope.insert({ ca[i].x, ca[i].y });
			if(pb[j][0] && pb[j][1])
				nope.insert({ cb[j].x, cb[j].y });
			both.insert(val);
		}
	for(int bad: nope)
		both.erase(bad);
	if(nope.empty() && !both.empty())
	{	// Participants know
		if(both.size() == 1u)
			printf("%d\n", *both.cbegin());
		else
			puts("0");
	}
	else
		puts("-1");
    return 0;
}
