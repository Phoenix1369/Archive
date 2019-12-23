map<int,int> cnt;
int N;

class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int K) {
        cnt.clear();
        for (int n: nums) {
            ++cnt[n];
        }
        while (!cnt.empty()) {
            int src = cnt.begin()->first;
            for (int k = 0; k < K; ++k) {
                int val = src + k;
                if (!cnt.count(val)) {
                    return false;
                }
                if (!--cnt[val]) {
                    cnt.erase(val);
                }
            }
        }
        return true;
    }
};

/*
[1,2,3,3,4,4,5,6]
4
[3,2,1,2,3,4,3,4,5,9,10,11]
3
[3,3,2,2,1,1]
3
[1,2,3,4]
3
>> true
>> true
>> true
>> false
*/
