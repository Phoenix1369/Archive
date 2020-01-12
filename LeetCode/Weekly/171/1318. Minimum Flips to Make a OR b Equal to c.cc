class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ret = 0;
        while (a || b || c) {
            if (c & 1) {
                if (!(a & 1) && !(b & 1)) {
                    ++ret;
                }
            } else {
                if (a & 1) ++ret;
                if (b & 1) ++ret;
            }
            c >>= 1;
            b >>= 1;
            a >>= 1;
        }
        return ret;
    }
};

/*
2
6
5
4
2
7
1
2
3
>> 3
>> 1
>> 0
*/
