vector<int> D;
vector<int> S;
int M;

class CustomStack {
public:
    CustomStack(int maxSize) {
        M = maxSize;
        D.clear();
        S.clear();
    }
    
    void push(int x) {
        if (S.size() == M) return;
        S.push_back(x);
        D.push_back(0);
    }
    
    int pop() {
        if (S.empty()) return -1;
        int val = D.back();
        D.pop_back();
        if (!D.empty()) {
            D.back() += val;
        }
        val += S.back();
        S.pop_back();
        return val;
    }
    
    void increment(int k, int val) {
        if (S.empty()) return;
        k = min((int)S.size(), k);
        --k;
        D[k] += val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
