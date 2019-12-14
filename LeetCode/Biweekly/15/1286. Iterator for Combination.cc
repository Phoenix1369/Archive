vector<string> subset;
string S;
string T;
int K;
unsigned pos;

class CombinationIterator {
public:
    CombinationIterator(string characters, int combinationLength) {
        S = move(characters);
        K = combinationLength;
        subset.clear();
        T.clear();
        dfs(0);
        pos = 0u;
    }
    
    string next() {
        return subset[pos++];
    }
    
    bool hasNext() {
        return pos < subset.size();
    }

private:
    void dfs(int cur) {
        if (T.size() == K) {
            subset.push_back(T);
            return;
        }
        if (cur >= S.size()) {
            return;
        }
        T.push_back(S[cur]);
        dfs(cur + 1);
        T.pop_back();
        dfs(cur + 1);
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
