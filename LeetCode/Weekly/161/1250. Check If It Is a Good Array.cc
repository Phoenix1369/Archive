class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        int G = 0;
        for (int a: nums) {
            G = gcd(a, G);
        }
        return (G == 1);
    }
    
private:
    int gcd(int a, int b) {
        return b ? gcd(b, a % b) : a;
    }
};
