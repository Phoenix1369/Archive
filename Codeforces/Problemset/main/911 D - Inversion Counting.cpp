#include <algorithm>
#include <cstdio>
const int MAXN = 1505;
int	A[MAXN]{ };
int B[MAXN], copy[MAXN];
int inv=0, N, Q;

void merge(int l, int m, int r)
{
	int i=l, j=m, k=l;
	for(int x = l; x < r; ++x)
		copy[x] = B[x];
	while((i < m) && (j < r))
		if(copy[i] < copy[j])
			B[k++] = copy[i++];
		else
		{
			inv += m-i;
			B[k++] = copy[j++];
		}
	while(i < m) B[k++] = copy[i++];
	while(j < r) B[k++] = copy[j++];
}

void merge_sort(int L, int R)
{
	if(R-L+1 <= 1) return;
	int M=(L+R)>>1;
	merge_sort(L  , M);
	merge_sort(M+1, R);
	merge(L, M+1, R+1);
}

int main()
{
	scanf("%d", &N);
	for(int i = 1; i <= N; ++i)
		scanf("%d", &A[i]);
	for(int i = 1; i <= N; ++i)
		B[i] = A[i];
	merge_sort(1, N); inv &= 1;
	scanf("%d", &Q);
	for(int _ = 0; _ < Q; ++_)
	{
		int d, l, r;
		scanf("%d%d", &l, &r);
		d = r-l+1;
		inv ^= (1LL*d*(d-1)>>1) & 1;
		puts((inv & 1) ? "odd" : "even");
	}
	return 0;
}