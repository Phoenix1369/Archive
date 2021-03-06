#define ALL(x) (x).begin(), (x).end()
typedef vector<int> vin;

class RLEIterator {
	vin b;

public:
	RLEIterator(vector<int> A) {
		b = vin(A);
		reverse(ALL(b));
	}

	int next(int n) {
		while(!b.empty() && n > b.back()) {
			n -= b.back();
			b.pop_back();
			b.pop_back();
		}
		if(b.empty()) {
			return -1;
		}
		b.back() -= n;
		return b.end()[-2];
	}
};
