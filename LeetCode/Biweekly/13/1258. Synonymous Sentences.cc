const int MAXW = 20;
map<string, int> C;
int dsu[MAXW];
int id, N;

istringstream iss;
ostringstream oss;
vector<string> ret;
vector<string> T;

class Solution {
public:
    vector<string> generateSentences(
            vector<vector<string>>& synonyms,
            string text
    ) {
        init();
        id = 0;
        for (auto& edge: synonyms) {
            auto& u = edge[0];
            auto& v = edge[1];
            int uid = add(u);
            int vid = add(v);
            unite(uid, vid);
        }
        N = split(text);
        ret.clear();
        dfs(0);
        return ret;
    }

private:
    void dfs(int pos) {
        if (pos == N) {
            ret.push_back(join());
            return;
        }
        if (!C.count(T[pos])) {
            return dfs(pos+1);
        }
        int x = find(C.at(T[pos]));
        for (auto itr: C) {
            if (find(itr.second) == x) {
                T[pos] = itr.first;
                dfs(pos + 1);
            }
        }
    }
    
    int add(const string& s) {
        if (!C.count(s)) {
            return C[s] = id++;
        }
        return C.at(s);
    }
    
    void init() {
        C.clear();
        T.clear();
        for (int i = 0; i < MAXW; ++i) {
            dsu[i] = i;
        }
    }
    
    // String Operations
    string join() {
        oss.str("");
        for (int i = 0; i < N; ++i) {
            if (i) oss << ' ';
            oss << T[i];
        }
        return oss.str();
    }
    
    int split(string s) {
        iss.str(s);
        while (iss >> s) {
            T.push_back(s);
        }
        return T.size();
    }
    
    // DSU
    int find(int u) {
        int v = u;
        while (v != dsu[v]) v = dsu[v];
        while (u != v) {
            int tmp = dsu[u];
            dsu[u] = v;
            u = tmp;
        }
        return u;
    }
    
    void unite(int u, int v) {
        u = find(u);
        v = find(v);
        if (u != v) dsu[u] = v;
    }
};
