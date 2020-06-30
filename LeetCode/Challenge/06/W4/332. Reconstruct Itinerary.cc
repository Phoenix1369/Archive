typedef string str;
const str SRC = "JFK";
map<str, map<str,int>> G;
vector<str> ret;
unsigned M;

class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        M = tickets.size();
        ++M;
        init();
        for (auto& e: tickets) {
            str& u = e[0];
            str& v = e[1];
            ++G[u][v];
        }
        ret.push_back(SRC);
        dfs(SRC);
        return ret;
    }

private:
    bool dfs(const str& u) {
        if (ret.size() == M) {
            return true;
        }
        if (!G.count(u)) {
            return false;
        }
        auto& H = G.at(u);
        for (auto itr = H.begin(); itr != H.end(); ++itr) {
            str v = itr->first;
            if (!--itr->second) {
                H.erase(v);
            }
            ret.push_back(v);
            if (dfs(v)) {
                return true;
            }
            ret.pop_back();
            ++H[v];
            itr = H.find(v);
        }
        return false;
    }

    void init() {
        G.clear();
        ret.clear();
    }
};
