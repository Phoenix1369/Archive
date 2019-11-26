typedef pair<int,int> pii;
unordered_map<int,int> ccnt, cnt;

class Solution {
public:
    int maxEqualFreq(vector<int>& nums) {
        init(nums.size());
        int pos = 1;
        int ret = 1;
        for (int x: nums) {
            if (cnt.count(x)) {
                int old = cnt.at(x);
                if (!--ccnt[old]) {
                    ccnt.erase(old);
                }
            }
            ++cnt[x];
            ++ccnt[cnt.at(x)];
            if (valid_prefix()) {
                ret = max(pos, ret);
            }
            ++pos;
        }
        return ret;
    }

private:
    void init(int N) {
        cnt.clear();
        cnt.reserve(N);
        ccnt.clear();
        ccnt.reserve(N);
    }
    
    bool valid_prefix() {
        if (ccnt.size() == 1u) {
            auto itr = ccnt.begin();
            return (itr->first == 1) || (itr->second == 1);
        }
        if (ccnt.size() != 2u) {
            return false;
        }
        auto itr = ccnt.begin();
        pii a = *itr;
        ++itr;
        pii b = *itr;
        if (a.first > b.first) {
            std::swap(a, b);
        }
        return
            ((a.first == 1) && (a.second == 1)) ||
            ((b.second == 1) && (a.first + 1 == b.first));
    }
};

/*
[2,2,1,1,5,3,3,5]
[1,1,1,2,2,2,3,3,3,4,4,4,5]
[1,1,1,2,2,2]
[10,2,8,9,3,8,1,5,2,3,7,6]
>> 7
>> 13
>> 5
>> 8
*/
