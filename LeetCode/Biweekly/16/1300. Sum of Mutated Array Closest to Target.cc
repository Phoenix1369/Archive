#define ALL(x) (x).begin(), (x).end()
const int INFN = 1e9+7;
vector<int> A;

class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        A = move(arr);
        int lo = 0;
        int hi = *max_element(ALL(A));
        while (lo < hi) {
            int x = (lo + hi) / 2;
            if (f(x) >= target) {
                hi = x;
            } else {
                lo = x + 1;
            }
        }
        lo = hi-1;
        int hidiff = abs(f(hi) - target);
        int lodiff = abs(f(lo) - target);
        return (hidiff < lodiff) ? hi : lo;
    }

private:
    int f(int x) {
        int sum = 0;
        for (int a: A) {
            sum += min(a, x);
        }
        return sum;
    }
};

/*
[4,9,3]
10
[2,3,5]
10
[60864,25176,27249,21296,20204]
56803
>> 3
>> 5
>> 11361
*/
