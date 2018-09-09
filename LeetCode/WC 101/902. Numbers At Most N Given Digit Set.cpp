class Solution {
	int A[20];
	int a=0;

public:
	int atMostNGivenDigitSet(vector<string>& D, int N) {
		while(N) {
			A[a++] = N % 10;
			N /= 10;
		}
		int mul=1, ret=0;
		for(int i = 1; i < a; ++i) {
			mul *= (int)D.size();
			ret += mul;
		}   // Leading zeroes
		set<int> C;
		for(string s: D) {
			C.insert(s[0]-'0');
		}
		for(int i = a-1; i >= 0; --i) {
			for(int j: C) {
				if(j < A[i]) {
					ret += mul;
				}
			}
			if(!C.count(A[i])) {
				break;
			} else if(!i) {
				++ret;
			}   // Perfect match
			mul /= (int)D.size();
		}
		return ret;
	}
};
