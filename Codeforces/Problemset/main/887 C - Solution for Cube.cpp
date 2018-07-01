#include <algorithm>
#include <cstdio>
const int MAXF = 6;
const int MAXN = MAXF<<2;
const int L[3] = { 0, 4, 4 }; // Length of S[i]
const int R[3][4] = {
	{ 1, 4, 5, 3 },
	{ 0, 4, 2, 3 },
	{ 0, 1, 2, 5 }
};
const int S[3][4][2] = {
	{ },
	{ {8,10}, {9,11}, {13,14}, {16,19} },
	{ {1,2}, {5,6}, {9,10}, {20,23} }
};
int  A[MAXN]{ };
bool F[MAXF]{ };

bool shift(int p)
{
	bool good, nxt, prv;
	good = nxt = prv = true;
	for(int i = 0; i < L[p]; ++i)
		std::swap(A[S[p][i][0]], A[S[p][i][1]]);
	for(int i = 0; i < 4; ++i)
	{	// Horizontal Pairings
		good &= (A[R[p][i]<<2  ] == A[R[p][i]<<2|1]);
		good &= (A[R[p][i]<<2|2] == A[R[p][i]<<2|3]);
	}
	for(int i = 0; i < 4; ++i)
		nxt &= (A[R[p][i]<<2] == A[R[p][(i+1)&3]<<2|2]);
	for(int i = 0; i < 4; ++i)
		prv &= (A[R[p][i]<<2] == A[R[p][(i+3)&3]<<2|2]);
	return	good && (nxt || prv);
}

bool solve()
{
	int cnt = 0;
	for(int i = 0; i < MAXF; ++i)
		if(F[i]) ++cnt;
	if(cnt != 2)
		return false;
	if(F[0] && F[2])
		return shift(0);
	else if(F[1] && F[5])
		return shift(1);
	else if(F[3] && F[4])
		return shift(2);
	return false;
}

int main()
{
	for(int i = 0; i < MAXN; ++i)
		scanf("%d", &A[i]);
	for(int i = 0; i < MAXF; ++i)
		F[i] = true;
	for(int i = 0; i < MAXN; ++i)
		F[i>>2] &= (A[i] == A[i & ~3]); // (i & ~3) == ((i>>2)<<2)
	puts(solve() ? "YES" : "NO");
	return 0;
}