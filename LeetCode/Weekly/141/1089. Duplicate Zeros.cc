vector<int> res;

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        res = move(arr);
        for (auto val: res) {
            arr.push_back(val);
            if (!val) {
                arr.push_back(val);
            }   // duplicate zeroes
        }
        while (arr.size() > res.size()) {
            arr.pop_back();
        }
    }
};

