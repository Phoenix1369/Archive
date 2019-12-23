const int BASE = 10;

class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int cnt = 0;
        for (int x: nums) {
            if (count_digits(x) & 1) continue;
            ++cnt;
        }
        return cnt;
    }

private:
    int count_digits(int x) {
        int ret = 0;
        while (x) {
            ++ret;
            x /= BASE;
        }
        return ret;
    }
};

/*
[12,345,2,6,7896]
[555,901,482,1771]
>> 2
>> 1
*/
