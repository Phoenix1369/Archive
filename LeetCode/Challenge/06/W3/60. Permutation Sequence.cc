#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

using __gnu_pbds::null_type;
using __gnu_pbds::rb_tree_tag;
using __gnu_pbds::tree;
using __gnu_pbds::tree_order_statistics_node_update;

typedef tree<
    int,
    null_type,
    less<int>,
    rb_tree_tag,
    tree_order_statistics_node_update
> ordered_set;

ordered_set D;
vector<int> F;
int K, N;

class Solution {
public:
    string getPermutation(int n, int k) {
        N = n;
        K = --k;
        init();
        string ret;
        while (N) {
            --N;
            int pos = K / F[N];
            K %= F[N];
            auto val = D.find_by_order(pos);
            ret.push_back(*val + '0');
            D.erase(val);
        }
        return ret;
    }

private:
    void init() {
        D.clear();
        F.clear();
        F.push_back(1);
        for (int i = 1; i <= N; ++i) {
            D.insert(i);
            F.push_back(F.back() * i);
        }
    }
};
