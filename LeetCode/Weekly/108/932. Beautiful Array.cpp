class Solution {
    typedef vector<int> vin;
public:
    vector<int> beautifulArray(int N) {
        vin ret{1};
        while ((int)ret.size() < N) {
            vin tmp;
            for (int& x: ret) {
                int y = x*2-1;
                if (y <= N) {
                    tmp.push_back(y);
                }
            }
            for (int& x: ret) {
                int y = x*2;
                if (y <= N) {
                    tmp.push_back(y);
                }
            }
            ret = std::move(tmp);
        }
        return ret;
    }
};  // Divide and Conquer - beauty is linear
