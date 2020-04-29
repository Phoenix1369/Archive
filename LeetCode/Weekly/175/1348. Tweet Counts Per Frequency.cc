constexpr int MINUTE = 60;
constexpr int HOUR = MINUTE * 60;
constexpr int DAY = HOUR * 24;
const int MAXQ = 1e4+5;
unordered_map<string, set<int>> T;

class TweetCounts {
public:
    TweetCounts() {
        T.reserve(MAXQ);
    }
    
    void recordTweet(string tweetName, int time) {
        T[tweetName].insert(time);
    }
    
    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        vector<int> ret;
        int delta = frequency(freq[0]);
        const auto& C = T[tweetName];
        auto itr = C.lower_bound(startTime);
        
        int head = startTime;
        while (head <= endTime) {
            int tail = min(head + delta, endTime + 1);
            int cnt = 0;
            while ((itr != C.end()) && (*itr < tail)) {
                ++cnt;
                ++itr;
            }
            ret.push_back(cnt);
            head = tail;
        }
        return ret;
    }

private:
    int frequency(char f) {
        switch (f) {
        case 'd': return DAY;
        case 'h': return HOUR;
        case 'm': return MINUTE;
        }
        return 0;
    }
};

/**
 * Your TweetCounts object will be instantiated and called as such:
 * TweetCounts* obj = new TweetCounts();
 * obj->recordTweet(tweetName,time);
 * vector<int> param_2 = obj->getTweetCountsPerFrequency(freq,tweetName,startTime,endTime);
 */
