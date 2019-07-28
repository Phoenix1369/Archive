#include <cstdio>
#include <unordered_set>
std::unordered_set<int> S, W;
int A, B, C, D, E, F;

int main()
{
	scanf(" %d%d%d%d%d%d", &A, &B, &C, &D, &E, &F);
	S.reserve(F);
	for(int i = 0; C*i <= F; ++i)
	for(int j = 0; C*i + D*j <= F; ++j)
		S.insert(C*i + D*j);
	W.reserve(F);
	for(int i = 0; 100*A*i <= F; ++i)
	for(int j = 0; 100*(A*i + B*j) <= F; ++j)
		if(i || j) W.insert(100*(A*i + B*j));
	int res[2] = { 100*A, 0 }; // Mass: Sugar+Water, Sugar
	for(auto s: S)
	for(auto w: W)
	{
		if((s > E*w/100) || (s+w > F)) continue;
		if(s * res[0] > res[1] * (s+w))
			res[0] = s+w, res[1] = s;
	}
	printf("%d %d\n", res[0], res[1]);
	return 0;
}