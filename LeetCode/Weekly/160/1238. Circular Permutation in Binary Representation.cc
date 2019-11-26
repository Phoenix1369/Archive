#define ALL(x) (x).begin(), (x).end()
vector<int> order;
int N;

class Solution {
public:
    vector<int> circularPermutation(int n, int start) {
        N = n;
        order.clear();
        generate(N-1);
        vector<int> ret;
        int val = 0;
        int L = 1 << N;
        for (int i = 0; i < L; ++i) {
            ret.push_back(val);
            if (i+1 < L) {
                int shift = order[i];
                val ^= (1 << shift);
            }
        }
        auto itr = find(ALL(ret), start);
        rotate(ret.begin(), itr, ret.end());
        return ret;
    }

private:
    void generate(int k) {
        if (k < 0) return;
        generate(k-1);
        order.push_back(k);
        generate(k-1);
    }
};

/*
2
3
3
2
>> [3,2,0,1]
>> [2,6,7,5,4,0,1,3]
*/
