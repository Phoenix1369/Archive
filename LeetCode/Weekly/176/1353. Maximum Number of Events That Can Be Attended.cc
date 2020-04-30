struct Event {
    int s, e;
    
    bool operator < (const Event& o) const {
        return (o.s != s) ? (o.s < s) : (o.e < e);
    }
};

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        priority_queue<Event> pq;
        for (auto e: events) {
            pq.push({e[0], e[1]});
        }
        int ret = 0;
        int time = 0;
        while (!pq.empty()) {
            Event cur = pq.top();
            pq.pop();
            if (cur.s < time) {
                pq.push({time, cur.e});
                continue;
            }   
            if (time < cur.s) {
                time = cur.s;
            }
            if (time <= cur.e) {
                ++time;
                ++ret;
            }
        }
        return ret;
    }
};
