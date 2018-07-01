#include <algorithm>
#include <cstdio>
#include <string>
#include <vector>
#define ALL(x) (x).begin(), (x).end()
typedef std::string str;
const int MAXA = 26;
const int MAXC = 1E5+5;
char buff[MAXC]{ };
bool here[MAXA]{ };
bool seen[MAXA]{ };
int	u[MAXA]{ }; // Previous
int	v[MAXA]{ }; // Next
std::vector<str> res;
str  word;
bool yes;
int N;

bool dfs(int cur, int f)
{
	if(cur == -1)
		return true;
	if(seen[cur]) // Cycle
		return yes = false;
	seen[cur] = true;
	return dfs((!f ? u : v)[cur], f);
}

int main()
{
	scanf("%d", &N);
	yes = true;
	for(int i = 0; i < MAXA; ++i)
		u[i] = v[i] = -1;
	for(int i = 0; i < N; ++i)
	{
		scanf(" %s", buff);
		word = buff;
		for(int j = 0; j < (int)word.size(); ++j)
		{
			if(j)
			{	// Prev Case
				if((	u[word[j]-'a'] == -1) || (
					u[word[j]-'a'] == word[j-1]-'a'))
					u[word[j]-'a'] =  word[j-1]-'a';
				else
					yes = false;
			}
			if(j+1 != (int)word.size())
			{	// Next Case
				if((	v[word[j]-'a'] == -1) || (
					v[word[j]-'a'] == word[j+1]-'a'))
					v[word[j]-'a'] =  word[j+1]-'a';
				else
					yes = false;
			}
			if(!yes) return puts("NO"), 0;
			here[word[j]-'a'] = true;
		}
	}
	for(int i = 0; i < MAXA; ++i) if(!seen[i])
		yes &= dfs(i, 0) && dfs(v[i], 1); // Cycle Detection
	if(!yes) return puts("NO"), 0;
	for(int i = 0; i < MAXA; ++i)
		seen[i] = false;
	for(int i = 0; i < MAXA; ++i) if(here[i] && !seen[i])
	{
		int C;
		for(C = i; u[C] != -1; C = u[C]);
		word = "";
		for(; C != -1; C = v[C])
		{
			word += 'a'+C;
			seen[C] = true;
		}
		res.push_back(word);
	}
	std::sort(ALL(res));
	for(auto s: res)
		printf("%s", s.c_str());
	putchar('\n');
	return 0;
}
