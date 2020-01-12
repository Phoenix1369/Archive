const int BASE = 10;

class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        vector<int> ret;
        for (int i = 1; i < n; ++i) {
            int j = n-i;
            if (nozero(i) && nozero(j)) {
                ret.push_back(i);
                ret.push_back(j);
                break;
            }
        }
        return ret;
    }

private:
    bool nozero(int x) {
        if (!x) {
            return false;
        }
        while (x) {
            int rem = x % BASE;
            if (!rem) {
                return false;
            }
            x /= BASE;
        }
        return true;
    }
};

/*
2
11
10000
69
1010
>> [1,1]
>> [2,9]
>> [1,9999]
>> [1,68]
>> [11,999]
*/
