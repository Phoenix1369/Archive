#include <algorithm>
#include <cstdio>
#include <utility>
#define CODE "platform_parkour"
#define x first
#define y second
typedef std::pair<double,double> pff;
const int MAXB = 30;
const int MAXM = 20;
const int MAXN = 2e5+5;
int A[MAXM], B[MAXM], D[MAXM], U[MAXM];
int H[MAXN], moun[MAXN], vall[MAXN];
// moun[i] -> allowed delta[i,i+1] if H[i] < H[i+1]
// vall[i] -> allowed delta[i,i+1] if H[i] > H[i+1]
int M, N, W, X, Y, Z;
int mnH, mxH;
int T;

bool f(double cost)
{
	pff ran = { std::max(H[mnH]-cost, 0.0), H[mnH]+cost };
	for(int i = mnH; i < mxH; ++i)
	{
		pff now = { std::max(H[i+1]-cost, 0.0), H[i+1]+cost };
		if((ran.y+moun[i] < now.x) || (now.y < ran.x-vall[i]))
			return false;
		// Intersect
		double ranx = std::max(ran.x-vall[i], now.x);
		double rany = std::min(ran.y+moun[i], now.y);
		ran = { std::max(ranx, 0.0), rany };
		if(ran.x > ran.y)
			return false;
	}
	return true;
}

int main()
{
	// freopen(CODE "_sample_input.txt", "r", stdin);
	// freopen(CODE "-single.txt", "r", stdin);
	freopen(CODE ".txt", "r", stdin);
	freopen(CODE ".out", "w", stdout);
	scanf("%d", &T);
	for(int t = 1; t <= T; ++t)
	{
		scanf(" %d%d", &N, &M);
		scanf(" %d%d", &H[1], &H[2]);
		scanf(" %d%d%d%d", &W, &X, &Y, &Z);
		for(int i = 3; i <= N; ++i)
			H[i] = ((1LL*W*H[i-2] % Z + 1LL*X*H[i-1] % Z) % Z + Y) % Z;
		for(int i = 1; i <= N; ++i)
			moun[i] = vall[i] = Z;
		mnH=N, mxH=0;
		for(int i = 0; i < M; ++i)
		{
			scanf(" %d%d%d%d", &A[i], &B[i], &U[i], &D[i]);
			if(B[i] < A[i])
			{
				std::swap(A[i], B[i]);
				std::swap(U[i], D[i]);
			}
			for(int j = A[i]; j < B[i]; ++j)
			{
				moun[j] = std::min(U[i], moun[j]);
				vall[j] = std::min(D[i], vall[j]);
			}
			mnH = std::min(std::min(A[i], B[i]), mnH);
			mxH = std::max(std::max(A[i], B[i]), mxH);
		}
		double lo=0.0, hi=1.0*Z;
		for(int i = 0; (lo < hi) && (i < MAXB); ++i)
		{
			double ce=(lo+hi)/2.0;
			if(f(ce))
				hi = ce;
			else
				lo = ce;
		}
		printf("Case #%d: %.9f\n", t, lo);
	}
    return 0;
}
