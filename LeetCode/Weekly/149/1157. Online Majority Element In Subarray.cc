#define ALL(x) (x).begin(), (x).end()

typedef vector<int> vin;
const int MAXA = 2e4+5;
const int SQTN = 142;
vin pos[MAXA];

// Pick a random element and count it.

class MajorityChecker {
    vin A;
    int N;

public:
    MajorityChecker(vector<int>& arr) {
        srand(time(NULL));

        A = move(arr);
        for (int i = 0; i < MAXA; ++i) {
            pos[i].clear();
        }

        N = A.size();
        for (int i = 0; i < N; ++i) {
            pos[A[i]].push_back(i);
        }
    }
    
    int query(int left, int right, int threshold) {
        int sz = (right - left + 1);
        for (int i = 0; i < SQTN; ++i) {
            int pos = left + (rand() % sz);
            if (count_range(left, right, A[pos]) >= threshold) {
                return A[pos];
            }
        }
        return -1;
    }

private:
    int count_range(int lhs, int rhs, int val) {
        if (pos[val].empty()) return 0;

        auto rtr = lower_bound(ALL(pos[val]), rhs);
        if (rtr == pos[val].end()) --rtr;
        auto ltr = lower_bound(ALL(pos[val]), lhs);
        if (ltr == pos[val].end()) --ltr;
        
        int rpos = rtr - pos[val].begin();
        int lpos = ltr - pos[val].begin();

        while ((rpos >= 0) && (pos[val][rpos] > rhs)) --rpos;
        while ((lpos >= 0) && (pos[val][lpos] >= lhs)) --lpos;

        return rpos - lpos;
    }
};

/**
 * Your MajorityChecker object will be instantiated and called as such:
 * MajorityChecker* obj = new MajorityChecker(arr);
 * int param_1 = obj->query(left,right,threshold);
 */
