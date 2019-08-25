class DinnerPlates {
    map<int, vector<int>> S;
    set<int> avail;
    int cap;
    
public:
    DinnerPlates(int capacity) {
        cap = capacity;
    }
    
    void push(int val) {
        if (avail.empty()) {
            avail.insert(S.size());
        }
        int pos = *avail.begin();
        S[pos].push_back(val);
        if (S[pos].size() == cap) {
            avail.erase(pos);
        }
    }
    
    int pop() {
        if (S.empty()) {
            return -1;
        }
        return popAtStack(S.rbegin()->first);
    }
    
    int popAtStack(int index) {
        if (S[index].empty()) {
            return -1;
        }
        int val = S[index].back();
        S[index].pop_back();
        avail.insert(index);
        if (S[index].empty()) {
            S.erase(index);
        }
        return val;
    }
};

/**
 * Your DinnerPlates object will be instantiated and called as such:
 * DinnerPlates* obj = new DinnerPlates(capacity);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAtStack(index);
 */
