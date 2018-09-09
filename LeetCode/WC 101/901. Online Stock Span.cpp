typedef vector<int> vin;

class StockSpanner {
	vin a, s;
	int i;

public:
	StockSpanner() {
		a.push_back(0);
		s.push_back(0);
		i = 1;
	}

	int next(int price) {
		while(!s.empty() && a[s.back()] <= price) {
			s.pop_back();
		}
		int ret = i-s.back();
		a.push_back(price);
		s.push_back(i);
		++i;
		return ret;
	}
};
