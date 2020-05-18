const int BASE = 2;
vector<int> D;

class Solution {
public:
    int findComplement(int num) {
        digits(num);
        for (int& d: D) d ^= 1;
        return number();
    }

private:
    void digits(int x) {
        D.clear();
        while (x) {
            D.push_back(x % BASE);
            x /= BASE;
        }
    }
    
    int number() {
        int num = 0;
        int M = D.size();
        for (int i = M-1; i >= 0; --i) {
            num = num * BASE + D[i];
        }
        return num;
    }
};
