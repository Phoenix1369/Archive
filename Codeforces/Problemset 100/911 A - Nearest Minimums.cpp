#include <cstdio>
#include <map>
#include <vector>
typedef std::vector<int> vin;
std::map<int,vin> freq;
int A, N;

int main()
{
	scanf("%d", &N);
	for(int i = 0; i < N; ++i)
	{
		scanf("%d", &A);
		freq[A].push_back(i);
	}
	int M = N;
	const vin& B = freq.begin()->second;
	for(int i = 1; i < (int)B.size(); ++i)
		M = std::min(B[i]-B[i-1], M);
	printf("%d\n", M);
	return 0;
}