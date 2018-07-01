#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <unordered_set>
#define MMS(x, y) memset((x), (y), sizeof (x))
typedef std::string str;
const int MAXA = 26;
const int MAXK = 2505;
const int MAXN = 5005;
str	A[MAXK]{ };
char buff[MAXN]{ };
std::unordered_set<str> note;
int cnt[MAXA], pos[4];
int D=0, K, N;

inline bool match(int idx)
{
	bool yes = true;
	int diff = 0, dnt[MAXA]{ };
	for(int j = 0; j < N; ++j)
	{
		int c = A[idx][j]-'a';
		yes &= (++dnt[c] <= cnt[c]);
		if(buff[j] != A[idx][j])
			++diff;
	}
	if(diff == 2)	return yes;
	if(diff)	return false;
	return std::any_of(cnt, cnt+MAXA, [](const int& c){ return c > 1; });
}

inline bool check(const str& cst)
{
	MMS(cnt, 0);
	strcpy(buff, cst.c_str());
	for(int i = 0; i < N; ++i)
		++cnt[buff[i]-'a'];
	for(int k = 0; k < D; ++k)
	for(int j = 0; j < N; ++j) if(j != pos[k])
	{
		bool yes = true;
		std::swap(buff[j], buff[pos[k]]);
		for(int i = 0; i < K; ++i)
			if(!match(i)) { yes = false; break; }
		if(yes) return true;
		std::swap(buff[j], buff[pos[k]]);
	}
	return false;
}

inline bool solve()
{
	auto fir = note.begin();
	auto sec = fir; ++sec;
	for(int i = 0; i < N; ++i)
		if(fir->at(i) != sec->at(i))
		{
			pos[D++] = i;
			if(D > 4) return false;
		}
	return check(*fir) || check(*sec);
}

int main()
{
	scanf(" %d%d", &K, &N);
	note.reserve(K);
	for(int i = 0; i < K; ++i)
	{
		scanf(" %s", buff);
		note.insert(A[i] = buff);
	}
	if(note.size() == 1U)
	{
		std::swap(buff[0], buff[1]);
		puts(buff);
	}
	else if(solve())
		puts(buff);
	else
		puts("-1");
	return 0;
}