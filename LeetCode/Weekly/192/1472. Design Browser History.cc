const int MAXQ = 5005;
string H[MAXQ];
int cur, tip;

class BrowserHistory {
public:
    BrowserHistory(string homepage) {
        cur = 0;
        tip = 0;
        H[cur] = move(homepage);
    }
    
    void visit(string url) {
        H[++cur] = url;
        tip = cur;
    }
    
    string back(int steps) {
        cur = max(cur - steps, 0);
        return H[cur];
    }
    
    string forward(int steps) {
        cur = min(cur + steps, tip);
        return H[cur];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
