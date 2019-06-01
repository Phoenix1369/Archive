#define ALL(x) (x).begin(), (x).end()

class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        if (a > b) swap(a, b);
        if (a > c) swap(a, c);
        if (b > c) swap(b, c);
        if ((c-a) == 2) {
            return {0, 0};
        }
        int maximum = c-a-2;
        if ((c-b) <= 2 || (b-a) <= 2) {
            return {1, maximum};
        }
        return {2, maximum};
    }
};

