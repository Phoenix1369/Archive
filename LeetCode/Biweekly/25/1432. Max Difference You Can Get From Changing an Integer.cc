#define ALL(x) (x).begin(), (x).end()
const int BASE = 10;
vector<int> D;

class Solution {
public:
    int maxDiff(int num) {
        int a = inc(num);
        int b = dec(num);
        return a - b;
    }

private:
    int dec(int n) {
        digits(n);
        int F = D[0];
        if (F == 1) {
            // early -> 0
            auto itr = find_if(ALL(D), [](int d) { return (d > 1); });
            int x = (itr != D.end()) ? *itr : 0;
            for (int& d: D) if (d == x) d = 0;
        } else {
            // first -> 1
            for (int& d: D) if (d == F) d = 1;
        }
        return number();
    }
    
    int inc(int n) {
        digits(n);
        // early -> 9
        auto itr = find_if(ALL(D), [](int d) { return (d < 9); });
        int x = (itr != D.end()) ? *itr : 9;
        for (int& d: D) if (d == x) d = 9;
        return number();
    }
    
    void digits(int n) {
        D.clear();
        while (n) {
            D.push_back(n % BASE);
            n /= BASE;
        }
        reverse(ALL(D));
    }
    
    int number() {
        int x = 0;
        for (int d: D) x = x * BASE + d;
        return x;
    }
};
