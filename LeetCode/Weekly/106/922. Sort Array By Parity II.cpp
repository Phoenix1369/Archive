class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        vector<int> split[3]{ };
        for (const auto& a: A) {
            split[a & 1].push_back(a);
        }
        while (!split[0].empty()) {
            for (int i = 0; i < 2; ++i) {
                split[2].push_back(split[i].back());
                split[i].pop_back();
            }
        }
        return split[2];
    }
};
