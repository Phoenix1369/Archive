#define ALL(x) (x).begin(), (x).end()
const int BASE = 10;

class Solution {
public:
    int subtractProductAndSum(int n) {
        auto D = get_digits(n);
        int p = accumulate(ALL(D), 1, [](int x, int y) { return x * y; });
        int s = accumulate(ALL(D), 0, [](int x, int y) { return x + y; });
        return p - s;
    }

private:
    vector<int> get_digits(int n) {
        vector<int> ret;
        while (n) {
            ret.push_back(n % BASE);
            n /= BASE;
        }
        return ret;
    }
};

/*
234
4421
>> 15
>> 21
*/
