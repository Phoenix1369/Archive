const int BASE = 10;
const int LOGN = 10;
int A[LOGN];

class Solution {
public:
	int atMostNGivenDigitSet(vector<string>& D, int N) {
        int a = 0;
		while (N) {
			A[a++] = N % BASE;
			N /= BASE;
		}
        set<int> C;
		for (string s: D) {
			C.insert(s[0]-'0');
		}
		int mul = 1;
        int ret = 0;
        // Strictly shorter
		for (int i = 1; i < a; ++i) {
			mul *= D.size();
			ret += mul;
		}
        // Prefix match
		for (int i = a-1; i >= 0; --i) {
			for (int j: C) {
				if (j < A[i]) {
					ret += mul;
				}
			}
			if (!C.count(A[i])) {
				break;
			} else if (!i) {
                // Perfect match
                ++ret;
			}
			mul /= (int)D.size();
		}
		return ret;
	}
};
