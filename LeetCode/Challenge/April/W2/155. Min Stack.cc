template <typename T>
using vec = vector<T>;

class MinStack {
    vec<int> M;
    vec<int> S;

public:
    /** initialize your data structure here. */
    MinStack() {
        M.clear();
        S.clear();
    }
    
    void push(int x) {
        if (M.empty() || (M.back() >= x)) {
            M.push_back(x);
        }
        S.push_back(x);
    }
    
    void pop() {
        if (M.back() == S.back()) {
            M.pop_back();
        }
        S.pop_back();
    }
    
    int top() {
        return S.back();
    }
    
    int getMin() {
        return M.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
