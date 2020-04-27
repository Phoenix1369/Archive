#define ALL(x) (x).begin(), (x).end()

struct Data {
    int id, r;
};

class Solution {
public:
    vector<int> filterRestaurants(
            vector<vector<int>>& restaurants,
            int veganFriendly,
            int maxPrice,
            int maxDistance
    ) {
        vector<Data> res;
        for (auto& r: restaurants) {
            int id = r[0];
            int rating = r[1];
            int v = r[2];
            int p = r[3];
            int d = r[4];
            if ((v >= veganFriendly) &&
                (p <= maxPrice) &&
                (d <= maxDistance)) {
                res.push_back({id, rating});
            }
        }
        sort(ALL(res), [](const Data& lhs, const Data& rhs) {
            if (lhs.r != rhs.r) {
                return lhs.r > rhs.r;
            }
            return lhs.id > rhs.id;
        });
        vector<int> ret;
        for (auto& d: res) {
            ret.push_back(d.id);
        }
        return ret;
    }
};
