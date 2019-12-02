class Solution {
public:
    vector<int> numOfBurgers(int T, int C) {
        if ((T < 2*C) || (T > 4*C) || (T & 1)) {
            return {};
        }
        int small = C;
        int jumbo = (T - 2*small) / 2;
        small -= jumbo;
        return { jumbo, small };
    }
};

/*
16
7
17
4
4
17
0
0
2
1
>> [1,6]
>> []
>> []
>> [0,0]
>> [0,1]
*/
