typedef std::vector<int> vin;

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        vin arr[2];
        for(int i: A) {
            arr[i&1].push_back(i);
        }
        for(int i: arr[1]) {
            arr[0].push_back(i);
        }
        return arr[0];
    }
};
