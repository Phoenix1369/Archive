#define ALL(x) (x).begin(), (x).end()
vector<int> A;

class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        A = move(nums);
        int lo = 1;
        int hi = *max_element(ALL(A));
        while (lo < hi) {
            int x = (lo + hi) / 2;
            if (f(x) <= threshold) {
                hi = x;
            } else {
                lo = x + 1;
            }
        }
        return lo;
    }

private:
    int f(int x) {
        int sum = 0;
        for (auto i: A) {
            sum += (i + x - 1) / x;
        }
        return sum;
    }
};

/*
[1,2,5,9]
6
[2,3,5,7,11]
11
[19]
5
>> 5
>> 3
>> 4
*/
