const int BASE = 10;

class Solution {
public:
    int maximum69Number (int num) {
        vector<int> D;
        while (num) {
            D.push_back(num % BASE);
            num /= BASE;
        }
        int ret = 0;
        bool edit = false;
        while (!D.empty()) {
            int val = D.back();
            D.pop_back();
            if (!edit && (val == 6)) {
                val = 9;
                edit = true;
            }
            ret = ret * BASE + val;
        }
        return ret;
    }
};
