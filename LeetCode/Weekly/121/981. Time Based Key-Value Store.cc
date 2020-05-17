#define ALL(x) (x).begin(), (x).end()
const int MAXQ = 1.2e5+5;
const string MT = "";
map<string, vector<pair<int, string>>> A;

class TimeMap {
public:
    /** Initialize your data structure here. */
    TimeMap() {
        A.clear();
    }
    
    void set(string key, string value, int timestamp) {
        A[key].emplace_back(timestamp, value);
    }
    
    string get(string key, int timestamp) {
        if (!A.count(key)) {
            return "";
        }
        const auto& series = A.at(key);
        auto itr = lower_bound(ALL(series), make_pair(timestamp+1, MT));
        if (itr == series.begin()) {
            return "";
        }
        --itr;
        return itr->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
