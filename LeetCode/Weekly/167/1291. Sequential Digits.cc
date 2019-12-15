#define ALL(x) (x).begin(), (x).end()
typedef long long lld;
const int BASE = 10;
vector<int> ret;
int hi, lo;

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        lo = low;
        hi = high;
        ret.clear();
        for (int k = 1; k < BASE; ++k) {
            dfs(k);
        }
        sort(ALL(ret));
        return ret;
    }

private:
    void dfs(lld val) {
        if (val > hi) {
            return;
        }
        if (val >= lo) {
            ret.push_back(val);
        }
        int rem = (val % BASE) + 1;
        if (rem < BASE) {
            dfs(val * BASE + rem);
        }
    }
};

/*
100
300
1000
13000
>> [123,234]
>> [1234,2345,3456,4567,5678,6789,12345]
*/
