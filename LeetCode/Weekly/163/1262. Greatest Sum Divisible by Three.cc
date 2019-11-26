#define ALL(x) (x).begin(), (x).end()
typedef vector<int> vin;
const int MAXK = 3;
vin cnt[MAXK];
int ret;

class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        init();
        for (int num: nums) {
            cnt[num % MAXK].push_back(num);
        }
        for (int i = 0; i < MAXK; ++i) {
            sort(ALL(cnt[i]));
        }
        ret = accumulate(ALL(nums), 0);
        int rem = ret % MAXK;
        int sub = compute(rem);
        ret -= sub;
        return ret;
    }

private:
    void init() {
        for (int i = 0; i < MAXK; ++i) {
            cnt[i].clear();
        }
    }
    
    int compute(int rem) {
        if (!rem) {
            return 0;
        }
        int x = ret;
        if (!cnt[rem].empty()) {
            x = min(cnt[rem].front(), x);
        }
        if (cnt[rem^3].size() >= 2u) {
            x = min(cnt[rem^3][0] + cnt[rem^3][1], x);
        }
        return x;
    }
};

/*
[3,6,5,1,8]
[4]
[1,2,3,4,4]
[2,6,2,2,7]
[3,1,2]
>> 18
>> 0
>> 12
>> 15
*/
