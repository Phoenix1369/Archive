class Solution {
public:
    int balancedStringSplit(string s) {
        int L = 0;
        int R = 0;
        int ret = 0;
        for (char c: s) {
            if (c == 'L') {
                ++L;
            } else {
                ++R;
            }
            if (L == R) {
                L = R = 0;
                ++ret;
            }
        }
        if (L) {
            ++ret;
        }
        return ret;
    }
};

/*
"RLRRLLRLRL"
"RLLLLRRRLR"
"LLLLRRRR"
"RLRRRLLRLL"
>> 4
>> 3
>> 1
>> 2
*/
