#define ALL(x) (x).begin(), (x).end()
template <typename T>
using vec = vector<T>;
const int MAXK = 3;

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        int N = products.size();
        int M = searchWord.size();
        sort(ALL(products));
        
        vec<vec<string>> ret;
        for (int i = 0; i < M; ++i) {
            string prefix = searchWord.substr(0, i + 1);
            auto ptr = lower_bound(ALL(products), prefix);
            ret.emplace_back();
            for (int j = 0; j < MAXK; ++j) {
                if (ptr == products.end()) {
                    break;
                }
                if (ptr->size() <= i) {
                    break;
                }
                if (ptr->substr(0, i + 1) != prefix) {
                    break;
                }
                ret.back().push_back(*ptr);
                ++ptr;
            }
        }
        return ret;
    }
};

/*
["mobile","mouse","moneypot","monitor","mousepad"]
"mouse"
["havana"]
"havana"
["bags","baggage","banner","box","cloths"]
"bags"
["havana"]
"tatiana"
*/
