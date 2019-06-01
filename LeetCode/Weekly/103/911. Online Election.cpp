#define ALL(x) (x).begin(), (x).end()
typedef std::vector<int> vin;
const int MAXN = 5005;

struct Data {
    int v, t, i;
    
    bool operator < (const Data &r) const {
        if (v != r.v) {
            return v < r.v;
        }
        return t < r.t;
    }
};
typedef std::priority_queue<Data, std::vector<Data>> pq;

class TopVotedCandidate {
    vin T;
    int ans[MAXN];

public:
    TopVotedCandidate(vector<int> persons, vector<int> times) {
        T = times;

        pq Q;
        std::map<int,int> cnt;
        int n = (int)persons.size();
        for(int i = 0; i < n; ++i) {
            ++cnt[persons[i]];
            Q.push({ cnt.at(persons[i]), times[i], persons[i] });
            ans[i] = Q.top().i;
        }
    }
    
    int q(int t) {
        auto ptr = std::upper_bound(ALL(T), t);
        if (ptr != T.begin())
            --ptr; // Should always happen
        return ans[ptr-T.begin()];
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj.q(t);
 */
