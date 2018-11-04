class RecentCounter {
    queue<int> q;

    const int DIFF = 3000;
public:
    RecentCounter() : q{} { }
    
    int ping(int t) {
        while(!q.empty() && (q.front() < t-DIFF)) {
            q.pop();
        }
        q.push(t);
        return q.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
