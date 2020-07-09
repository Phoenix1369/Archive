const int BASE = 10;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        int N = digits.size();
        for (int i = N-1; carry && (i >= 0); --i) {
            digits[i] += carry;
            if (digits[i] == BASE) {
                digits[i] = 0;
                carry = 1;
            } else {
                carry = 0;
            }
        }
        if (carry) {
            digits.insert(digits.begin(), carry);
        }
        return digits;
    }
};
